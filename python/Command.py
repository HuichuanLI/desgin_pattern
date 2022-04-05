# -*- coding: utf-8 -*-

import abc


class VmReceiver(object):
    """
    命令接收者，真正执行命令的地方
    """

    def start(self):
        print("Virtual machine start")

    def stop(self):
        print("Virtual machine stop")


class Command(object):
    """
    命令抽象类
    """
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def execute(self):
        """
        命令对象对外只提供 execute 方法
        """
        pass


class StartVmCommand(Command):
    """
    开启虚拟机的命令
    """

    def __init__(self, recevier):
        """
        使用一个命令接收者初始化
        """
        self.recevier = recevier

    def execute(self):
        """
        真正执行命令的时候命令接收者开启虚拟机
        """
        self.recevier.start()


class StopVmCommand(Command):
    """
    停止虚拟机的命令
    """

    def __init__(self, recevier):
        """
        使用一个命令接收者初始化
        """
        self.recevier = recevier

    def execute(self):
        """
        真正执行命令的时候命令接收者关闭虚拟机
        """
        self.recevier.stop()


class ClientInvoker(object):
    """
    命令调用者
    """

    def __init__(self, command):
        self.command = command

    def do(self):
        self.command.execute()


if __name__ == '__main__':
    recevier = VmReceiver()
    start_command = StartVmCommand(recevier)
    # 命令调用者同时也是客户端，通过命令实例也执行真正的操作
    client = ClientInvoker(start_command)
    client.do()

    # 能告诉命令接收者执行不同的操作
    stop_command = StopVmCommand(recevier)
    client.command = stop_command
    client.do()
