# Bloku-grandiniu-technologijos

1 užduotis

failai: data2a.txt, data2b.txt, data3a.txt, data3b.txt, data5.txt buvo sugeneruoti https://www.random.org/strings/, bei http://www.unit-conversion.info/texttools/random-string-generator/ pagalba.


Nuskaitomi failai: data1a.txt ir data1b.txt.
abu failai turi po vieną simbolį.
Rezultatas:
"Input1: a
Input2: s
Output1: c31328f507050624b984515ead289acbea5fb7f4
Output2: af1328271715f2da9184f55edfd49a877c5fc786
Nesutampa"
trumpos įvestys yra teisingai išplečiamos į 40 simbolių hash'ą.


Nuskaitomi failai: data2a.txt ir data2b.txt.
abu failai turi po 100000 simbolių.
"Output1: 61501ab738dca8dcdf5abf0f72c5a8b0c2f5a713
Output2: f0b61464d2b1190f9e26765ce9ad8e1fe55992a6
Nesutampa"
ilgos įvestys yra teisingai sutrumpinamos į 40 simbolių hash'ą.


Nuskaitomi failai: data3a.txt ir data3b.txt.
abu failai turi po 100000 simbolių, bet skiriasi tik 1 simboliu.
"Output1: 61501ab738dca8dcdf5abf0f72c5a8b0c2f5a713
Output2: 66501ac840e4af9f6b5ac10f836ba8dec3f5af14
Nesutampa"
ilgos įvesčių hash'ai skiriasi, nei jei įvestys skiriasi tik 1 simboliu.


Nuskaitomas failas: data4.txt.
failas yra tuščias.
"Output: bb401416b28097c3a1f4f04cdb59c8f47a4fc133"
data4.txt yra tuščias failas, bet hash'as vistiek yra sugeneruojamas, gautas hash'as yra deterministinis.


Nuskaitomas failas: data5.txt.
faile yra 100000 porų
nebuvo rasta nei viena pora, kurios hash'ai sutaptų.
skaičiavimas trunka apie 5s


Nuskaitomas failas: konstitucija.txt.
PASTABA: programa neatpažysta lietuviškų raidžių, tačiau supranta kad jos skiriasi nuo paprastų, bei kad skiriasi tarpusavį
Code::Blocks su GNU GCC kompileriu gauna tokį rezultatą po kompiliacijos :
Jei rezultatai yra spausdinami: "Process returned 0 (0x0)   execution time : 1.023 s"
Jei rezultatai nėra spausdinami: "Process returned 0 (0x0)   execution time : 0.122 s"
programos išvestis yra apskaičiuojama pakankamai efektyviai.
