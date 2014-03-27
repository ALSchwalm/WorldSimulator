from simulator import *
from defaultItems import *

class Baker(BaseProfession):
    related_items = [Sword]
    def __init__(self):
        BaseProfession.__init__(self, Baker.__name__)
        self.skillMap = {}
