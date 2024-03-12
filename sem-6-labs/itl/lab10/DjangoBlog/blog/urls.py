from django.urls import include, path 
from blog.views import archive,create_blogpost

urlpatterns = [ 
	path('', archive, name='archive'),
	path('create/', create_blogpost, name='create_blogpost'),
 ]