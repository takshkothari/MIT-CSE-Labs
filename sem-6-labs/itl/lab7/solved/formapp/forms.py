from django import forms

class RegForm(forms.Form):
	title = forms.CharField(widget=forms.Textarea)
	description = forms.CharField(widget=forms.Textarea)
	views = forms.IntegerField(widget=forms.TextInput)
	available = forms.BooleanField(widget=forms.CheckboxInput)
