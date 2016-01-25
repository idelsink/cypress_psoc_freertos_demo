Cypress PSoC FreeRTOS Demo
==========================
This projects holds example projects to use [FreeRTOS](http://www.freertos.org/) in [PSoC Creator](http://www.cypress.com/products/psoc-creator-integrated-design-environment-ide) for the Cypress Programmable System-on-Chip (PSoC).

## Suported devices
The following devices are supported in these examples:
-  Cypress [PSoC 4](http://www.cypress.com/products/psoc-4) (Cortex M0)  
-  Cypress [PSoC 5](http://www.cypress.com/products/psoc-5lp) (Cortex M3)

## Motivation
In a private project I wanted to use FreeRTOS in my system and I was ristricted to a [PSoC](http://www.cypress.com/products/32-bit-arm-cortex-m-psoc) chip from Cypress. For this reason I implemeted this for a PSoC 4 and PSoC 5 chip.

## Requirements
- GNU Tools ARM Embedded
- [PSoC Creator](http://www.cypress.com/products/psoc-creator-integrated-design-environment-ide)

## Setup
Just download and open the `.cywrk` file with PSoC Creator.

## Tests
This software is tested with PSoC Creator 3.3 CP1 (3.3.0.410) And with FreeRTOS V8.2.2.

## Devices
The following dev kits were used to test the projects.
#### PSoC 4
- [CY8CKIT-044 PSoC® 4 M-Series Pioneer Kit](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-044-psoc-4-m-series-pioneer-kit)
- [CY8CKIT-042 PSoC® 4 Pioneer Kit](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-042-psoc-4-pioneer-kit)

#### PSoC 5
- [CY8CKIT-059 PSoC® 5LP Prototyping Kit](http://www.cypress.com/documentation/development-kitsboards/cy8ckit-059-psoc-5lp-prototyping-kit-onboard-programmer-and)

## Project structure
`/FreeRTOS/` Holds the FreeRTOS Kernel.  
`/PSoC 4 FreeRTOS Demo/` Holds the PSoC 4 Demo project. Device is set to: [CY8C4247AZI-M485ES](http://www.cypress.com/part/cy8c4247azi-m485). This chip is used on the CY8CKIT-044 Dev kit.  
`/PSoC 5 FreeRTOS Demo/` Holds the PSoC 5 Demo project. Device is set to: [CY8C5888LTI-LP097](http://www.cypress.com/part/cy8c5888lti-lp097). This chip is used on the CY8CKIT-059 Dev kit.  

## License
>You can check out the full license [here](https://github.com/MrCrazyID/Cypress_PSoC_FreeRTOS_Demo/blob/master/LICENSE)

This project is licensed under the terms of the **MIT** license.
