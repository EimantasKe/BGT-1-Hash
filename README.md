# Bloku-grandiniu-technologijos

1 užduotis

failai: data2a.txt, data2b.txt, data3a.txt, data3b.txt, data5.txt buvo sugeneruoti https://www.random.org/strings/, bei http://www.unit-conversion.info/texttools/random-string-generator/ pagalba.
data6.txt sugeneruotas su test6generator, naudojant data5.txt

Nuskaitomi failai: data1a.txt ir data1b.txt.
abu failai turi po vieną simbolį.
Rezultatas:
"Output1: 9e3460cc066a83b4cf6f9232e120fcbcc404842b
Output2: 5410e48028a46edceefec400d6e81cd42068d446
Nesutampa"
trumpos įvestys yra teisingai išplečiamos į 40 simbolių hash'ą.


Nuskaitomi failai: data2a.txt ir data2b.txt.
abu failai turi po 100000 simbolių.
"Output1: c19062dff8ecf0c03b62031b5631c838e639f3eb
Output2: a87020c87088e890a0c060c080787008306810a8
Nesutampa"
ilgos įvestys yra teisingai sutrumpinamos į 40 simbolių hash'ą.


Nuskaitomi failai: data3a.txt ir data3b.txt.
abu failai turi po 100000 simbolių, bet skiriasi tik 1 simboliu.
"Output1: c19062dff8ecf0c03b62031b5631c838e639f3eb
Output2: fee07c62b08806001a6c3acaa43e3010742e7a7a
Nesutampa"
ilgos įvesčių hash'ai skiriasi, nei jei įvestys skiriasi tik 1 simboliu.


Nuskaitomas failas: data4.txt.
failas yra tuščias.
"Output: 43c01c3496d099d7335c14c4db2f989820556b43"
data4.txt yra tuščias failas, bet hash'as vistiek yra sugeneruojamas, gautas hash'as yra deterministinis.


Nuskaitomas failas: data5.txt.
faile yra 100000 porų
nebuvo rasta nei viena pora, kurios hash'ai sutaptų.

Nuskaitomas failas: data6.txt
faile yra 200,000 poru, porose eilutės skiriasi 1 simboliu
minimali "skirtingumo" reikšmė - 57
maksimali "skirtingumo" reikšmė - 139
vidurkinė "skirtingumo" reikšme - 90.74

Nuskaitomas failas: konstitucija.txt.
Code::Blocks su GNU GCC kompileriu gauna tokį rezultatą po kompiliacijos :
Jei rezultatai yra spausdinami: Process returned 0 (0x0)   execution time : 0.646 s
Jei rezultatai nėra spausdinami: "Process returned 0 (0x0)   execution time : 0.136 s"
programos išvestis yra apskaičiuojama pakankamai efektyviai.
