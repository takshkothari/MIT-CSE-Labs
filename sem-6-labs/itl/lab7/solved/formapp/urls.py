from django.urls import re_path as url 
from . import views 
urlpatterns = [ 
	url(r'', views.home_view, name='index'), 
] 