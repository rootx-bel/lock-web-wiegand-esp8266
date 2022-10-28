from django.db import models
import datetime

class History(models.Model):
    owner_card = models.CharField(max_length=255, default='', name='Владелец')
    addr = models.CharField(max_length=255, default='', name='Адрес_метки')
    time = models.DateTimeField(default=datetime.datetime.now(), name='Время')

    def __str__(self):
        return f'{self.Владелец}'

    @classmethod
    def create(cls):
        obj = cls( Время=datetime.datetime.now())
        return obj

    class Meta:
        verbose_name = "История"
        verbose_name_plural = "История"

class Tags(models.Model):
    owner = models.CharField(max_length=255, default='', name='Владелец')
    addr = models.CharField(max_length=255, default='', name='Адрес_метки')
    time = models.DateTimeField(default=datetime.datetime.now(), name='Последнее_использование')
    counter = models.CharField(max_length=1024, default='0', name='Количество_использований')
    work = models.BooleanField(default=False, name='Состояние')
    
    def __str__(self):
        return f'{self.Владелец}'

    class Meta:
        verbose_name = "Рабочие метки"
        verbose_name_plural = "Рабочие метки"