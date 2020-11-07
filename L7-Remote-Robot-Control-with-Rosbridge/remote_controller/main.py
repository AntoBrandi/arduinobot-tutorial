from ros_interface import RosInterface
from messenger import Messenger

ros = RosInterface()

if __name__ == "__main__":
    ros.connect()

    while True:
        print("What would you like to do with your robot?")
        print("1 for send a message to the robot")
        print("2 for send joint positions")
        user_input = input()
        try:
            selected_task = int(user_input)
            if selected_task == 1:
                Messenger(ros)
            elif selected_task == 2:
                pass
            else:
                print("Invalid Input")
        except ValueError:
            print("Invalid Input")
