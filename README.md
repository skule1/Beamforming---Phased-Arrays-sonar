# Beamforming - Phased Arrays sonar

Denne rutinen styrer 8 tråder i Arduino for å kontrollere Phased array og Beamforming med 8 sonar høyttalere. Hver tråd starter opp med en felles funksjon som mottar parameter for port, offset, fase, ampltude og navn. En puls trigger tråden som venter en tidsperiode offset. Dette er en global tidsvariable som venter en tidsperiode for pulsene blir sendt. Denne offset-parameteren vil fange opp på bd positive og negatve faseendringer. til hve enkelt node. Slik kan hver node styres hver for seg for å få et god beanforming resultat.

Burst på alle kanaler (8 stk), er synkrionisert. fase ok, men tidskonstantene er ikke sjekket.
Burst ved hjelp av analogWrite(port.--);
