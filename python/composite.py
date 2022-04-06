# -*- coding: utf-8 -*-
import abc


class Worker(object):
    """
    员工抽象类
    """
    __metaclass__ = abc.ABCMeta

    def __init__(self, name):
        self.name = name

    @abc.abstractmethod
    def work(self):
        pass


class Employe(Worker):
    """
    员工类
    """
    __metaclass__ = abc.ABCMeta

    def work(self):
        print("Employ: %s start to work " % self.name)


class Leader(Worker):
    """
    领导类
    """

    def __init__(self, name):
        self.members = []
        super(Leader, self).__init__(name)

    def add_member(self, employe):
        if employe not in self.members:
            self.members.append(employe)

    def remove_member(self, employe):
        if employe in self.members:
            self.members.remove(employe)

    def work(self):
        print("Leader: %s start to work" % self.name)
        for employe in self.members:
            employe.work()


if __name__ == '__main__':
    employe_1 = Employe("employe_1")
    employe_2 = Employe("employe_2")
    leader_1 = Leader("leader_1")
    leader_1.add_member(employe_1)
    leader_1.add_member(employe_2)

    employe_3 = Employe("employe_3")
    leader_2 = Leader("leader_2")
    leader_2.add_member(employe_3)
    leader_2.add_member(leader_1)

    leader_2.work()
