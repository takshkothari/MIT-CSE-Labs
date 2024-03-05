from django.urls import path
from . import views 

urlpatterns = [
    path('firstPage/',views.home,name='firstpage'),
    path('secondPage/',views.display,name='secondPage'),
]

