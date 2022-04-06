class SingletonMeta(type):
    '''单例类的元类'''

    def __init__(cls, *args, **kwargs):
        print('【SingletonMeta.__init__】初始化类')
        print('【SingletonMeta.__init__】cls:', cls)
        print('【SingletonMeta.__init__】id(cls):', id(cls))
        # 定义一个私有属性
        cls.__instance = None

    def __call__(cls, *args, **kwargs):
        '''对 Singleton 类进行实例化时调用这个方法'''
        print('【SingletonMeta.__call__】创建 Singleton 的实例')
        if cls.__instance is None:
            # 调用 SingletonMeta 的父类 type 的 __call__ 方法生成前者的实例
            # super 指的是 SingletonMeta 的父类 type
            # cls.__instance = type.__call__(cls, *args, **kwargs)
            cls.__instance = super().__call__(*args, **kwargs)
            return cls.__instance
        else:
            return cls.__instance


print('11111111111111111111111111111111111111111111111111111111111111')


class Singleton(metaclass=SingletonMeta):
    def __init__(self):
        # 对类进行实例化时，会打印这个，多次实例化操作只会打印一次
        # 因为只执行一次元类的 __call__ 方法，而 __init__ 方法是由前者内部调用的
        print('【Singleton.__init__】Creating Spam')


print('22222222222222222222222222222222222222222222222222222222222222')

# 在定义 Singleton 时，就调用了元类的初始化方法打印了类的 ID
# 此处再次打印类的 ID
print('类 Singleton 的 ID:', id(Singleton))
# 把类看作实例的话，元类相当于类的类
# 在类的外部获取实例的双下私有属性的格式是：_类名属性名
# 打印类的私有属性 __instance 的值
print('类 Singleton 的 __instance 属性值：',
      Singleton._SingletonMeta__instance)

print('33333333333333333333333333333333333333333333333333333333333333')

# 对类进行实例化，打印实例属性
s1 = Singleton()
print(id(s1))
s2 = Singleton()
print(id(s2))
