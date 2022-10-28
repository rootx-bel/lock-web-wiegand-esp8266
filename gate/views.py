from django.http import HttpResponse
from django.apps import apps
import datetime

def api(request):
    if request.method == 'GET' and request.GET.get('addr') is not None:
        answ = False
        info = request.GET.get('addr')
        Tags = apps.get_model('interface', 'Tags')
        History = apps.get_model('interface', 'History')
        hist = History.create()
        hist.Адрес_метки = info
        try:
            data = Tags.objects.get(Адрес_метки=info)
            if data.Состояние == True:
                answ = True
                data.Последнее_использование = datetime.datetime.now()
                data.Количество_использований = int(data.Количество_использований) + 1
                data.save()
                hist.Владелец=data.Владелец
            else:
                answ = False
        except:
            answ = False
            hist.Владелец='Unknown'
        hist.save()
        return HttpResponse(answ)