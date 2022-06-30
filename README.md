# OpenCV_and_tesseract
Bot for Albion Online market

Обновления для бота пока выходить не будут. Спасибо за понимание

Предупреждение!
Оговорюсь, что это может привести к блокировке аккаунта, так как я не знаком с политикой игры, и возможно это противоречит правилам, 
однако бот никак не модифицирует файлы игры, поэтому отследить бота античитом будет проблемой. Бот сделан для разрешения 1920х1080 (и для других разрешений, но на них мало тестировался). Необходимо также выбрать в настройках размер интерфейса по-умолчанию и английский язык. Советую для начала опробовать бота на небольших партиях предметов с маленькой стоимостью, чтобы понять его возможности и проблемные моменты, если возникнут вопросы по использованию или найдете неправильную логику (или просто баг, краш, зависание) буду рад помочь.

Руководство по использованию:
https://youtu.be/zakgIiXpaW0

Для полноценной работы, необходимо установить OpenCV и tesseract:

установка tesseract - https://www.youtube.com/watch?v=2kWvk4C1pMo&list=LL&index=5

сам tesseract - https://github.com/UB-Mannheim/tesseract/wiki

OpenCV - https://www.youtube.com/watch?v=Ny3GM1octbo

Opencv 4.5.5 - https://opencv.org/releases/

Так же, после распаковки архива, измените путь к библиотеке SFML: https://youtu.be/54SkBSKNiP8

Перед запуском проекта, убедитесь что выбрана вкладка Release, а не Debug https://imgur.com/a/hRD6RqJ

Если возникают вопросы, оставляйте комментарии под роликами или в пишите в дискорд Мераб#5740

Предметы, которые нужно взять если вы выбрали следующие категории:
* Curse: {Great Cursed Staff, Demonic Staff, Lifecurse Staff}
* Arcane: {Great Arcane Staff, Enigmatic Staff, Witchwork Staff}
* Fire: {Great Fire Staff, Infernal Staff}
* Frost: {Great Frost Staff, Glacial Staff}
* Holy: {Great Holy Staff, Divine Staff}
* Nature: {Great Nature Staff, Wild Staff, Druidic Staff}
  
* Axe: {Battleaxe, Greataxe, Halberd, Carrioncaller}
* Dagger: {Dagger Pair, Claws}
* Hammer: {Polehammer, Great Hammer, Tombhammer}   
* Mace: {Heavy Mace, Morning Star, Bedrock Mace}
* Sword: {Broadsword, Claymore, Dual Swords, Clarent Blade}   
  
* OffHand: {Tome of Spells, Shield, Sarcopfagus, Torch}  
  
* Hood: {Stalker Hood, Mercenary Hood, Hunter Hood, Assassin Hood}
* Jacket: {Stalker Jacket, Mercenary Jacket, Hunter Jacket, Assassin Jacket}
* Shoes: {Stalker Shoes, Mercenary Shoes, Hunter Shoes, Assassin Shoes}  
  
* Helmet: {Soldier Helmet, Knight Helmet, Guardian Helmet, Graveguard Helmet}  
* Armor: {Soldier Armor, Knight Armor, Guardian Armor, Graveguard Armor}  
* Boots: {Soldier Boots, Knight Boots, Guardian Boots, Graveguard Boots} 
  
* Bag: {Bag}  
* SatchelOfInsight: {SatchelOfInsight}


Изменения

* v. 0.3.0 
1. Добавлена возможность пользоваться ботом при разных разрешениях экрана, для того чтобы указать необходимое разрешение, в папке с ботом будет файл Config.txt там необходимо изменить разрешение.

* v. 0.3.0 
1. Добавлены категории предметов: Sword, OffHand.
2. Добавлена возможность ставить ордера на покупку, для этого достаточно отсканировать цены на черном рынке, и уже на любом другом рынке во второй вкладке нажать "Order". ВЕЩИ В ИНВЕНТАРЕ ДОЛЖНЫ БЫТЬ! Для изменения количества предметов выставлемых на ордер, нужно зайти в файл Items.h, пролистать в самый низ, там будет переменная ListItemLimitOrder, внутри нее можно изменять количество.
3. Обновление предметов по ордеру, делается во вкладке ордера.
4. Изменена система продажи вещей, после нажатия на "Sell" нужно указать сколько вещей нужно выставить, чтобы не считать ставьте с запасом, так как оно работает быстро.

* v. 0.2.0 
1. Добавлена кнопка Sell для продажи КУПЛЕННЫХ БОТОМ вещей из инвентаря, перед использованием необходимо зайти во вторую вкладку маркета (Sell)
2. Добавлена кнопка PrintB для просмотра КУПЛЕННЫХ БОТОМ вещей и их средней стоимости
3. Изменен принцип покупки вещей, теперь не нужно брать с собой вещи, чтобы их купить, НО если предмет имеет одинаковое название с артефактом, то его нужно брать (на данный момент это тольок Алебарда)






