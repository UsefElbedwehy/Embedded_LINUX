class animals_class():
    def __init__(self):
        print("Animals constructor is called")

    def animals_speak(self):
        print("Animals is speaking")

    def __animal_Dont(self):
        print("Animals dont talk")

    def access_private_function(self):
        self.__animal_Dont()

    def __del__(self):
        print("animals destructor")


animals_var = animals_class()
animals_var.access_private_function()