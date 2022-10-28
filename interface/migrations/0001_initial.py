# Generated by Django 4.1.2 on 2022-10-28 17:28

import datetime
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='History',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('Адрес метки', models.CharField(default='', max_length=255)),
                ('Время', models.DateTimeField(default=datetime.datetime(2022, 10, 28, 20, 28, 23, 605810))),
                ('Владелец', models.CharField(default='', max_length=255)),
            ],
            options={
                'verbose_name': 'История',
                'verbose_name_plural': 'История',
            },
        ),
        migrations.CreateModel(
            name='Tags',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('Адрес метки', models.CharField(default='', max_length=255)),
                ('Последнее использование', models.DateTimeField(default=datetime.datetime(2022, 10, 28, 20, 28, 23, 606810))),
                ('Владелец', models.CharField(default='', max_length=255)),
                ('Количество использований', models.CharField(default='0', max_length=1024)),
            ],
            options={
                'verbose_name': 'Рабочие метки',
                'verbose_name_plural': 'Рабочие метки',
            },
        ),
    ]
