# -*- coding: utf-8 -*-

import abc


class Fishing(object):
    """
    钓鱼模板基类
    """
    __metaclass__ = abc.ABCMeta

    def finishing(self):
        """
        钓鱼方法中，确定了要执行哪些操作才能钓鱼
        """
        self.prepare_bait()
        self.go_to_riverbank()
        self.find_location()
        print("start fishing")

    @abc.abstractmethod
    def prepare_bait(self):
        pass

    @abc.abstractmethod
    def go_to_riverbank(self):
        pass

    @abc.abstractmethod
    def find_location(self):
        pass


class JohnFishing(Fishing):
    """
    John 也想去钓鱼，它必须实现钓鱼三步骤
    """

    def prepare_bait(self):
        """
        从淘宝购买鱼饵
        """
        print("John: buy bait from Taobao")

    def go_to_riverbank(self):
        """
        开车去钓鱼
        """
        print("John: to river by driving")

    def find_location(self):
        """
        在岛上选择钓点
        """
        print("John: select location on the island")


class SimonFishing(Fishing):
    """
    Simon 也想去钓鱼，它也必须实现钓鱼三步骤
    """

    def prepare_bait(self):
        """
        从京东购买鱼饵
        """
        print("Simon: buy bait from JD")

    def go_to_riverbank(self):
        """
        骑自行车去钓鱼
        """
        print("Simon: to river by biking")

    def find_location(self):
        """
        在河边选择钓点
        """
        print("Simon: select location on the riverbank")


if __name__ == '__main__':
    # John 去钓鱼
    f = JohnFishing()
    f.finishing()

    # Simon 去钓鱼
    f = SimonFishing()
    f.finishing()
