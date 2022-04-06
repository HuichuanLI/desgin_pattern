class BaseMeta(type):
    def __new__(metacls, name, bases, namespace, **kwargs):
        # 如果 name 不是基类的名字，那就是创建子类啦
        # 如果并且子类没有提供 bar 属性，那就不予创建这个子类
        if name != 'Base' and 'bar' not in namespace:
            raise TypeError('bad user class')
        return super().__new__(metacls, name, bases, namespace, **kwargs)

class Base(object, metaclass=BaseMeta):
    def foo(self):
        return self.bar()


if __name__ == '__main__':
    class Base1(Base):
        def bar(self):
            ...
    print('Base1 创建完成')

    class Base2(Base):
        ...
    print('Base2 创建完成')