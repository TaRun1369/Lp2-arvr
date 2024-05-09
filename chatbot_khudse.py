import re
import random
from datetime import datetime

greetings = ['Hello!','Hi','Hey There!','Greetings!','Nice to see you']
thank_you = ['thank you visit again!','Our pleasure','We love your presense!','we know we are good']
prescription = ['Take this medicine twice a day','Take this medicine after meal','Take this medicine before meal','Take this medicine with water','Take this medicine with milk']
facilities = ['We have all the facilities','We have all the facilities you need','We have all the facilities you want','We have all the facilities you are looking for','We have all the facilities you are searching for']
appointment = ['You can book your appointment by calling us','You can book your appointment by visiting us','You can book your appointment by online','You can book your appointment by our app','You can book your appointment by our website']

greeting_pattern = re.compile(r'hello|hi|hey',re.IGNORECASE)
thank_you_pattern = re.compile(r'thank you|thanks',re.IGNORECASE)
prescription_pattern = re.compile(r'prescription|med',re.IGNORECASE)
facilities_pattern = re.compile(r'facilities|facility|help',re.IGNORECASE)
appointment_pattern = re.compile(r'appointment|book|schedule',re.IGNORECASE)



def chatbot():
    print('Hostipal wale : ' + random.choice(greetings))
    while(True):
        user_input= input('You : ')
        print('Hospita wale :')
        if re.search(greeting_pattern,user_input):
            print(random.choice(greetings))
        elif re.search(thank_you_pattern,user_input):
            print(random.choice(thank_you))
        elif re.search(prescription_pattern,user_input):
            print(random.choice(prescription))
        elif re.search(facilities_pattern,user_input):
            print(random.choice(facilities))
        elif re.search(appointment_pattern,user_input):
            print(random.choice(appointment ) )
            date = input('to book now Enter the date for appointment (dd/mm/yyyy) : ')
            print( ' appointment scheduled on ' + date)
        elif user_input == 'exit':
            print('Goodbye! Have a nice day!')
            break
        else:
            print("Sorry I am not able to understand you, Please rephrase this")

chatbot()