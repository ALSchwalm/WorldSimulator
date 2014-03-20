from simulator import *
from abc import abstractmethod

class Item(BaseItem):
    related_items = []
    default_attributes = {"a" : False}
    def __init__(self):
        BaseItem.__init__(self)


class Knife(BaseWeapon):
    def __init__(self):
        Item.__init__(self, Knife.__name__)

    def make():
        self.attributes = {"a" : True}

    default_attributes = {"a" : False}

    def getRequiredItems(self):
        return [
            (Dagger, lambda item: True)
        ]


class Dagger(BaseWeapon):
    related_items = [Knife]
    def __init__(self):
        Item.__init__(self, Dagger.__name__)
        self.attributes = {"a" : False}

    default_attributes = {"a" : False}

    def getRequiredItems(self):
        return [
            (Dagger, lambda item: item.attributes["a"])
        ]

class House(BaseContainer):
    def __init__(self):
        BaseContainer.__init__(self, House.__name__)

    default_attributes = {"habitable" : False}
