from django.contrib import admin 
import site 
from blog.models import BlogPost

from blog import models

class BlogPostAdmin(admin.ModelAdmin):
	list_display = ('title', 'timestamp')
admin.site.register(models.BlogPost,BlogPostAdmin) 