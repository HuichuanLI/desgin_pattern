class ListMeta(type):
    '''
    这就是一个元类，可以理解为“它的实例是类”
    '''

    # 参数 metacls 指代元类自身
    # 参数 cls_name 是要创建的类的类名
    # 参数 super_cls_tuple 就是新建的类需要继承的父类的元组
    # 参数 args_dict 为字典，它有一些 key ，例如 __module__ 、__doc__ 等
    # 此外类中的属性也会加进来，例如下面的 name 属性
    def __new__(metacls, cls_name, super_cls_tuple, args_dict):
        args_dict['add'] = lambda self, value: self.append(value)
        # return type.__new__(metacls, cls_name, 父类的元组, args_dict)
        # 为了便于研究，上面的一行代码改写成了下面的 4 行代码
        a = type.__new__(metacls, cls_name, super_cls_tuple, args_dict)
        print('-------a 就是 List 类:', a)
        print('-------List 类的属性:', dir(a))
        return a


# 下面这个就是我们要实现的类
class List(list, metaclass=ListMeta):
    '''
    创建 List 类时，会调用元类 ListMeta 的 __new__ 方法
    返回值是调用 type 的 __new__ 方法，该方法会将父类的“非私有属性”赋值给 List 类
    '''
    name = '哈喽World'


if __name__ == '__main__':
    new_list = List()
    if hasattr(new_list, 'add'):
        print()
        print('new_list 有 add 属性')