from django import forms

class CarForm(forms.Form):
    mans=(
        ('Bugatti','Bugatti'),
        ('Ferari','Ferari'),
        ('Lamborghini','Lamborghini'),
        ('Mini Cooper', 'Mini Cooper'),
        ('Batmobile', 'Batmobile')
        )
    manufacturer = forms.ChoiceField(widget=forms.Select,choices=mans)
    model = forms.CharField()