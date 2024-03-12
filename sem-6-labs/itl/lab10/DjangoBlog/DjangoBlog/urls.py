from django.contrib import admin
from django.urls import path
from django.urls import include
# Uncomment the next two lines to enable the admin:

urlpatterns = [
	 path('blog/', include('blog.urls')), 
	 path('admin/',admin.site.urls),
]