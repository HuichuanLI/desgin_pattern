class Singleton:
    def __new__(cls, *args, **kw):
        if not hasattr(cls, '_Singleton__instance'):
            cls.__instance = super().__new__(cls, *args, **kw)
        print('实例化时打印实例 ID:', id(cls.__instance))
        return cls.__instance


s1 = Singleton()
s2 = Singleton()

print('s1 is s2:', s1 is s2)