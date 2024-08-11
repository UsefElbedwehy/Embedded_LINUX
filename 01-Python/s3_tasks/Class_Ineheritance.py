class animals:
    def __init__(self):
        print("Animals constructor is called")

    def animals_speak(self):
        print("Animals speak")

    def __del__(self):
        print("Animals destructor is called")


class cat(animals):
    def __init__(self):
        super().__init__()
        print("Cat constructor is called")

    def Eat(self):
        print("Cat is eating")

    def __del__(self):
        print("Cat destructor is called")
        return super().__del__()
    


cat_n1 = cat()
cat_n1.animals_speak()
cat_n1.Eat()
