# -*- coding: utf-8 -*-

import abc


class AbsShow(object):
    """
    抽象显示对象
    """

    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def show(self):
        pass


class AdminShow(AbsShow):
    """
    管理员的显示操作
    """

    def show(self):
        return "show with admin"


class UserShow(AbsShow):
    """
    普通用户的显示操作
    """

    def show(self):
        return "show with user"


class Question(object):
    """
    问题对象，使用策略模式之后的作法
    """

    def __init__(self, show_obj):
        self.show_obj = show_obj

    def show(self):
        return self.show_obj.show()


if __name__ == '__main__':
    user_show = UserShow()  # 用户显示类的实例
    admin_show = AdminShow()  # 管理员显示类的实例
    q = Question(user_show)  # 这个问题实例的显示方式是「用户显示」
    print('用户显示：', end=' ')
    q.show()
    q.show_obj = admin_show  # 修改问题的属性就可以修改显示方式啦
    # 这叫做策略模式的「互换行为」
    print('管理员显示：', end=' ')
    q.show()
