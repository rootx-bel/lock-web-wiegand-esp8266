from django.shortcuts import render
from django.contrib.auth.decorators import login_required

def index(request):
    return render(request, 'interface/index.html')

@login_required(login_url='home')
def history(request):
    return render(request, 'interface/index.html')

@login_required(login_url='home')
def manage(request):
    return render(request, 'interface/index.html')