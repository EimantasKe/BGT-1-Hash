# Bloku-grandiniu-technologijos

1 užduotis

failai: data2a.txt, data2b.txt, data3a.txt, data3b.txt, data5.txt buvo sugeneruoti https://www.random.org/strings/, bei http://www.unit-conversion.info/texttools/random-string-generator/ pagalba.


Nuskaitomi failai: data1a.txt ir data1b.txt.
abu failai turi po vieną simbolį.
Rezultatas:
"Output1: 03130815070506041904111e0d081a0b0a1f1714
Output2: 0f1308071715121a1104151e1f141a071c1f0706
Nesutampa"
trumpos įvestys yra teisingai išplečiamos į 40 simbolių hash'ą.


Nuskaitomi failai: data2a.txt ir data2b.txt.
abu failai turi po 100000 simbolių.
"Output1: 01101a17181c081c1f1a1f0f1205081002150713
Output2: 101614041211190f1e06161c090d0e1f05191206
Nesutampa"
ilgos įvestys yra teisingai sutrumpinamos į 40 simbolių hash'ą.


Nuskaitomi failai: data3a.txt ir data3b.txt.
abu failai turi po 100000 simbolių, bet skiriasi tik 1 simboliu.
"Output1: 01101a17181c081c1f1a1f0f1205081002150713
Output2: 06101a0800040f1f0b1a010f030b081e03150f14
Nesutampa"
ilgos įvesčių hash'ai skiriasi, nei jei įvestys skiriasi tik 1 simboliu.


Nuskaitomas failas: data4.txt.
failas yra tuščias.
"Output: 1b001416120017030114100c1b1908141a0f0113"
data4.txt yra tuščias failas, bet hash'as vistiek yra sugeneruojamas, gautas hash'as yra deterministinis.


Nuskaitomas failas: data5.txt.
faile yra 100000 porų
nebuvo rasta nei viena pora, kurios hash'ai sutaptų.


Nuskaitomas failas: konstitucija.txt.
PASTABA: programa nepalaiko lietuviškų raidžių.
Code::Blocks su GNU GCC kompileriu gauna tokį rezultatą po kompiliacijos :
Jei rezultatai yra spausdinami: "Process returned 0 (0x0)   execution time : 0.840 s"
Jei rezultatai nėra spausdinami: "Process returned 0 (0x0)   execution time : 0.136 s"
programos išvestis yra apskaičiuojama pakankamai efektyviai.
