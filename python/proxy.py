# -*- coding: utf-8 -*-
from time import sleep


class Redis(object):
    """
    用于模拟 redis 服务
    """

    def __init__(self):
        """
        使用字典存储数据
        """
        self.cache = dict()

    def get(self, key):
        """
        获取数据
        """
        return self.cache.get(key)

    def set(self, key, value):
        """
        设置数据
        """
        self.cache[key] = value


class Image(object):
    """
    图片对象，图片存在七牛云存储中，我们只保存了一个地址
    """

    def __init__(self, name):
        self.name = name

    @property
    def url(self):
        sleep(2)
        return "https://dn-syl-static.qbox.me/img/logo-transparent.png"


class Page(object):
    """
    用于显示图片
    """

    def __init__(self, image):
        """
        需要图片进行初始化
        """
        self.image = image

    def render(self):
        """
        显示图片
        """
        print(self.image.url)


redis = Redis()


class ImageProxy(object):
    """
    图片代理，首次访问会从真正的图片对象中获取地址，以后都从 Redis 缓存中获取
    """

    def __init__(self, image):
        self.image = image

    @property
    def url(self):
        addr = redis.get(self.image.name)
        if not addr:
            addr = self.image.url
            print("Set url in redis cache!")
            redis.set(self.image.name, addr)
        else:
            print("Get url from redis cache!")
        return addr


if __name__ == '__main__':
    img = Image(name="logo")
    proxy = ImageProxy(img)
    page = Page(proxy)
    # 首次访问
    page.render()
    print("")
    # 第二次访问
    page.render()
