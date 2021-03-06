/**
 * @author Jan Beran (xberan43)
 * Projekt do predmetu IMS na FIT VUT v Brne (2019/2020)
 * @date 5.12.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "modelib.h"
#include "loglib.h"

void logDay(int verbosity)
{
    if(MlogFrequency > daily) return;
    printf("======================\n"
           "Daily log #%d\n"
           "----------------------\n",Mdays);
    printf("GHG [g CO2 eq.]: %lf\n", MdailyCF);
    if(verbosity > 0)
    {
        printf("Production [kWh]: %ld\n",MdailyProductionKWH);
        if(verbosity > 1)
        {
        }
    }
    printf("======================\n");
}


void logYear(int verbosity)
{
    if(MlogFrequency > yearly) return;
    static int flag = 1;

    if(flag)
    {
        printf("####################################################\n"
               "Yearly log #%d\n"
               "----------------------\n", Myears);
        if(verbosity>0)
        {
            printf("Percentage of each power plant type:\n"
                   "*Coal:      %f %%\n"
                   "*Nuclear:   %f %%\n"
                   "*Wind:      %f %%\n"
                   "*Hydro:     %f %%\n"
                   "*Biomass:   %f %%\n"
                   "*Solar:     %f %%\n"
                   "*Gas:       %f %%\n"
                   "*Other:     %f %%\n",
                   MactualPercentageProduceCoal, MactualPercentageProduceNuclear, MactualPercentageProduceWind,MactualPercentageProduceHydro,
                   MactualPercentageProduceBiomass, MactualPercentageProduceSolar, MactualPercentageProduceGas, MactualPercentageProduceOther);
            if(verbosity > 1)
            {
                printf("Installed power of each power plant type:\n"
                       "*Coal:      %lu kW\n"
                       "*Nuclear:   %lu kW\n"
                       "*Wind:      %lu kW\n"
                       "*Hydro:     %lu kW\n"
                       "*Biomass:   %lu kW\n"
                       "*Solar:     %lu kW\n"
                       "*Gas:       %lu kW\n"
                       "*Other:     %lu kW\n",
                       MactualInstalledPowerKWCoal, MactualInstalledPowerKWNuclear, MactualInstalledPowerKWWind,MactualInstalledPowerKWHydro,
                       MactualInstalledPowerKWBiomass, MactualInstalledPowerKWSolar, MactualInstalledPowerKWGas, MactualInstalledPowerKWOther);
            }
        }
        flag = 0;
    }
    else
    {
        printf("------------------------\n");
        printf("GHG [g CO2 eq.]*10**9: %lf\n", MyearCF/1000000000.);
        if(verbosity > 0)
        {
            printf("Production [GWh]: %ld\n",MyearlyProductionGWH);
            if(verbosity > 1)
            {

            }
        }
        flag = 1;
    }


}


void logTotal(int verbosity)
{
    printf("**************************************\n"
           "**************************************\n"
           "Total log\n"
           "----------------------\n");
    printf("GHG [g CO2 eq.]*10**12: %lf\n", MfinalCFkg/1000000000.);
    printf("Daily production [kWh] %ld\n", MdailyProductionKWH);
    if(verbosity > 0)
    {
        printf("Years: %d\n", Myears);
        printf("Percentage of each power plant type:\n"
               "*Coal:      %f %%\n"
               "*Nuclear:   %f %%\n"
               "*Wind:      %f %%\n"
               "*Hydro:     %f %%\n"
               "*Biomass:   %f %%\n"
               "*Solar:     %f %%\n"
               "*Gas:       %f %%\n"
               "*Other:     %f %%\n",
               MactualPercentageProduceCoal, MactualPercentageProduceNuclear, MactualPercentageProduceWind,MactualPercentageProduceHydro,
               MactualPercentageProduceBiomass, MactualPercentageProduceSolar, MactualPercentageProduceGas, MactualPercentageProduceOther);
        if(verbosity > 1)
        {
            printf("------------------------\n");
            printf("Installed power of each power plant type:\n"
                   "*Coal:      %lu kW\n"
                   "*Nuclear:   %lu kW\n"
                   "*Wind:      %lu kW\n"
                   "*Hydro:     %lu kW\n"
                   "*Biomass:   %lu kW\n"
                   "*Solar:     %lu kW\n"
                   "*Gas:       %lu kW\n"
                   "*Other:     %lu kW\n",
                   MactualInstalledPowerKWCoal, MactualInstalledPowerKWNuclear, MactualInstalledPowerKWWind,MactualInstalledPowerKWHydro,
                   MactualInstalledPowerKWBiomass, MactualInstalledPowerKWSolar, MactualInstalledPowerKWGas, MactualInstalledPowerKWOther);
        }
    }
    printf("**************************************\n"
           "**************************************\n");
}