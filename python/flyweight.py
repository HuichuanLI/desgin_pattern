# 使用装饰器，闭包实现内部状态统一
def flyweight(cls):
    instances = dict()
    # 匿名函数内部调用字典的 setdefault 方法设置键值对
    # 参数元组作为 key ，类的实例作为 value
    # 如果参数元组已存在，也就是实例化时提供的参数与之前某次相同
    # 则不再对类进行实例化，返回字典中对应的 value ，也就是类的实例
    return (lambda *args, **kargs:
            instances.setdefault(
                (args, tuple(kargs.items())),
                cls(args, kargs)
            )
            )


@flyweight
class Spam():

    def __init__(self, a, b):
        self.a = a
        self.b = b


# 创建实例
instance01 = Spam(1, 2)
instance02 = Spam(2, 2)
instance03 = Spam(1, 2)
instance04 = Spam(1, 2)

# 运行结果
print('id(instance01):', id(instance01))
print('id(instance02):', id(instance02))
print('id(instance03):', id(instance03))
print('id(instance04):', id(instance04))
print('type(instance01):', type(instance01))
print('type(instance02):', type(instance02))
