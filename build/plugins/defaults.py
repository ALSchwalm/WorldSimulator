from simulator import *

class Sword(BaseWeapon):
    related_items = []
    default_attributes = {}
    def __init__(self):
        Item.__init__(self, Knife.__name__)
        additional_attributes = {}
        self.attributes = dict(Knife.default_attributes.items() +
                               additional_attributes.items())

        self.requiredItems = []
        self.damageModifiers = {
            damage_type.piercing : 2,
            damage_type.slashing : 2,
            damage_type.blunt    : 0.5
        }

class Dagger(BaseWeapon):
    related_items = []
    default_attributes = {}
    def __init__(self):
        Item.__init__(self, Dagger.__name__)
        additional_attributes = {}
        self.attributes = dict(Dagger.default_attributes.items() +
                               additional_attributes.items())

        self.requiredItems = []
        self.damageModifiers = {
            damage_type.piercing : 2,
            damage_type.slashing : 2,
            damage_type.blunt    : 0.5
        }

class House(BaseContainer):
    default_attributes = {"habitable" : True}
    def __init__(self):
        BaseContainer.__init__(self, House.__name__)
        additional_attributes = {}
        self.requiredItems = []
        self.attributes = dict(House.default_attributes.items() +
                               additional_attributes.items())
