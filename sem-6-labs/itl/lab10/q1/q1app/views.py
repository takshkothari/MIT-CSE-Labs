from django.shortcuts import render
from .models import Category, Page
from .forms import CategoryForm,PageForm
from django.http import HttpResponseRedirect

def index(request):
    categories = Category.objects.all()
    pages = Page.objects.all()
    return render(request, 'index.html', {'categories': categories,'pages': pages,'cateform':CategoryForm(),'pageform':PageForm()})

def addCategory(request):
    if request.method=="POST":
        form  = CategoryForm(request.POST)
        if form.is_valid():
            form.save()
    return HttpResponseRedirect('/')

def addPage(request):
    if request.method=="POST":
        form  = PageForm(request.POST)
        if form.is_valid():
            form.save()
    return HttpResponseRedirect('/')