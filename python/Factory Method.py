# -*- coding: utf-8 -*-

import random
import abc


class BasicCourse:
    """
    基础课程
    """

    def __init__(self, course_name):
        self.course_name = course_name

    def get_labs(self):
        return "基础课程《{}》的实验列表...".format(self.course_name)

    def __str__(self):
        return "BasciCourse"


class ProjectCourse:
    """
    项目课程
    """

    def __init__(self, course_name):
        self.course_name = course_name

    def get_labs(self):
        return "项目课程《{}》的实验列表...".format(self.course_name)

    def __str__(self):
        return "ProjectCourse"


class Factory(metaclass=abc.ABCMeta):
    """
        抽象工厂类
        """

    @abc.abstractmethod
    def create_course(self):
        pass


class BasicCourseFactory(Factory):
    """
        基础课程工厂类
        """

    @classmethod
    def create_course(cls, course_name):
        return BasicCourse(course_name)


class ProjectCourseFactory(Factory):
    """
        项目课程工厂类
        """


    @classmethod
    def create_course(cls, course_name):
        return ProjectCourse(course_name)


def get_factory():
    """
        随机获取一个工厂类
        """
    return random.choice([BasicCourseFactory, ProjectCourseFactory])()


if __name__ == '__main__':
    # 创建一门基础课《Linux 基础入门》
    course1 = BasicCourseFactory.create_course('Linux 基础入门')
    print(course1.get_labs())
    # 创建一门项目课《Python 设计模式》
    course2 = ProjectCourseFactory.create_course('Python 设计模式')
    print(course2.get_labs())
