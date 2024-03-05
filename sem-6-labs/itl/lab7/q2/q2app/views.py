from django.shortcuts import render
from .forms import StudForm
# Create your views here.

def home(request):
    context = {}
    form = StudForm(request.POST or None)
    context['form'] = form
    return render(request,'firstPage.html',context)

def display(request):
    context = {}
    name = 'Taksh'
    rollno = '54'
    subject = 'PE2'
    if request.method == "POST":
        loginform  = StudForm(request.POST)
        if loginform.is_valid():
            name = loginform.cleaned_data['name']
            rollno = loginform.cleaned_data['rollno']
            subject = loginform.cleaned_data['subject']
            # request.session['name'] = name
        else:
            loginform  = StudForm()
    context['name'] = name
    context['rollno'] = rollno
    context['subject'] = subject
    return render(request,'secondPage.html',context)