from tkinter import *
import random

QuestionBank = [['Variables names cannot start with digit', True],
                ["x='1'+1 is a valid statement", True],
                ['= and == can be used interchangeably', False],
                ['logical operator and has higher precedence than or', True],
                ['String type is immutable', True],
                ['x,y = y,x swaps the values of x and y', True],
                ['2=x is a valid statement', False],
                ['Variable names can be 50 letters long', True]
                ]

# making 4 random questions
random.shuffle(QuestionBank)
QuestionBank = QuestionBank[:4]


# make quiz class inherit from UI class
class Quiz():
    def __init__(self, main):
        self.root = main
        self.root.title('Python Quiz : done by XXX')
        self.root.geometry('500x500')
        self.root.resizable(0, 0)
        self.current = 0
        self.score = 0
        # make a start button at the top that will start the quiz and when clicked will hide the start button
        self.start_button = Button(self.root, text='Start', command=self.start_quiz)
        self.start_button.pack()
        # make a label that will show the question below the start button
        self.question_label = Label(self.root, text='Question will appear here', font=('Helvetica', 14))
        self.question_label.pack(pady=4)
        self.label = Label(self.root, text='', bg='#f0f0f0', font=('Arial', 12))
        self.label.pack()
        self.label.pack_forget()
        self.radio_var = IntVar()
        self.radio_var.set(0)
        self.option_a = Radiobutton(self.root, text='Option 1', variable=self.radio_var, value=1)
        self.option_a.pack(pady=4)
        self.option_b = Radiobutton(self.root, text='Option 2', variable=self.radio_var, value=2)
        self.option_b.pack(pady=4)
        self.submit_button = Button(self.root, text='Submit', command=self.submit_answer)
        self.next_button = Button(self.root, text='Next', command=self.next_question)
        self.option_a.config(state=DISABLED)
        self.option_b.config(state=DISABLED)
        self.next_button.config(state=DISABLED)
        self.submit_button.config(state=DISABLED)

        # make a inline next_button and submit_button using pack()
        self.next_button.pack()
        self.submit_button.pack()
        self.correct_answer = Text(self.root, width=50, height=15, bg='#f0f0f0', font=('Arial', 12))
        self.correct_answer.pack()
        self.correct_answer.configure(state='disabled')

    def start_quiz(self):
        self.start_button.config(state=DISABLED)
        self.submit_button.config(state=NORMAL)
        self.option_a.config(state=NORMAL)
        self.option_b.config(state=NORMAL)
        self.correct_answer.configure(state='normal')
        self.correct_answer.delete(1.0, END)
        self.correct_answer.insert(END, 'Select answer and click Submit.')
        self.correct_answer.configure(state='disabled')
        self.next_button.pack()
        self.option_a.pack()
        self.option_b.pack()
        self.question_label.pack()
        self.submit_button.pack()
        self.correct_answer.pack()
        self.show_question()

    def show_question(self):
        # show the question
        self.question_label['text'] = "Q" + str(self.current + 1) + ". " + QuestionBank[self.current][0]
        # show the options
        self.option_a['text'] = 'True'
        self.option_b['text'] = 'False'

    def submit_answer(self):
        # if submit button is clicked then check if the answer is correct
        if int(self.radio_var.get()) == 0:
            self.correct_answer.configure(state='normal')
            self.correct_answer.insert(END, "\nPlease select answer for question " + str(self.current + 1))
            self.correct_answer.configure(state='disabled')
            self.submit_button.config(state=NORMAL)
        elif int(self.radio_var.get()) == 1:
            self.option_a_m()
            self.submit_button.config(state=DISABLED)
            self.next_button.config(state=NORMAL)
        elif int(self.radio_var.get()) == 2:
            self.option_b_m()
            self.submit_button.config(state=DISABLED)
            self.next_button.config(state=NORMAL)

    def next_question(self):
        self.next_button.config(state=DISABLED)
        self.radio_var.set(0)
        self.option_a.config(state=NORMAL)
        self.option_b.config(state=NORMAL)
        self.submit_button.config(state=NORMAL)
        self.current += 1
        if self.current == len(QuestionBank):
            self.show_result()

        else:
            self.show_question()

    def show_result(self):
        self.label.pack_forget()
        self.correct_answer.configure(state='normal')
        self.correct_answer.insert(END,
                                   '\nQuiz Completed ! Total Correct answer {} out of {}\nClick On Start To Start '
                                   'Again.'.format(
                                       self.score, len(QuestionBank)))
        # We need to call the _init_ method code somehow from here to re-initiate UI.
        self.question_label['text'] = "Question will appear here"
        self.correct_answer.configure(state='disabled')
        self.start_button.config(state=NORMAL)
        self.next_button.config(state=DISABLED)
        self.submit_button.config(state=DISABLED)
        self.option_a.config(state=DISABLED)
        self.option_b.config(state=DISABLED)
        self.current = 0
        self.score = 0

    def option_a_m(self):
        self.correct_answer.configure(state='normal')
        if QuestionBank[self.current][1]:
            self.score += 1
            self.correct_answer.insert(END, "\nQuestion " + str(self.current + 1) + " Correct!")
        else:
            self.correct_answer.insert(END, "\nQuestion " + str(self.current + 1) + " Incorrect!")
        self.option_a.config(state=DISABLED)
        self.option_b.config(state=DISABLED)
        self.correct_answer.configure(state='disabled')

    def option_b_m(self):
        self.correct_answer.configure(state='normal')
        if not QuestionBank[self.current][1]:
            self.score += 1
            self.correct_answer.insert(END, "\nQuestion " + str(self.current + 1) + " Correct!")
        else:
            self.option_b.config(state=DISABLED)
            self.correct_answer.insert(END, "\nQuestion " + str(self.current + 1) + " Incorrect!")
        self.option_a.config(state=DISABLED)
        self.option_b.config(state=DISABLED)
        self.correct_answer.configure(state='disabled')


root = Tk()
# make a quiz object
quiz = Quiz(root)
# run the root
root.mainloop()
