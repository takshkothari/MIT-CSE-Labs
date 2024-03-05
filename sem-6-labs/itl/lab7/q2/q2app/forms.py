from django import forms

class StudForm(forms.Form):
    name = forms.CharField()
    rollno = forms.CharField()
    subs=(
        ('PE1','PE1'),
        ('PE2','PE2'),
        ('EEFM','EEFM'),
        ('DS', 'DS'),
        ('PCAP', 'PCAP')
        )
    subject = forms.ChoiceField(widget=forms.Select,choices=subs)
