# bspcov

<details>

* Version: 1.0.3
* GitHub: https://github.com/statjs/bspcov
* Source code: https://github.com/cran/bspcov
* Date/Publication: 2025-08-18 19:20:30 UTC
* Number of recursive dependencies: 180

Run `revdepcheck::cloud_details(, "bspcov")` for more info

</details>

## Newly broken

*   checking installed package size ... NOTE
    ```
      installed size is  8.3Mb
      sub-directories of 1Mb or more:
        data   8.0Mb
    ```

## In both

*   checking package dependencies ... NOTE
    ```
    Package suggested but not available for checking: ‘hdbinseg’
    ```

# DeclareDesign

<details>

* Version: 1.1.0
* GitHub: https://github.com/DeclareDesign/DeclareDesign
* Source code: https://github.com/cran/DeclareDesign
* Date/Publication: 2025-10-15 08:30:15 UTC
* Number of recursive dependencies: 190

Run `revdepcheck::cloud_details(, "DeclareDesign")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Complete output:
      > library(testthat)
      > library(DeclareDesign)
      Loading required package: randomizr
      Loading required package: fabricatr
      Loading required package: estimatr
      > 
      > library(AER)
    ...
        │ 
        │ estimator <- declare_estimator(Y ~ Z, inquiry = my_inquiry) 
        │ 
        │ my_design <- construct_design(steps = steps) 
        │ 
      
      [ FAIL 9 | WARN 0 | SKIP 9 | PASS 634 ]
      Error:
      ! Test failures.
      Execution halted
    ```

# ggplot2

<details>

* Version: 4.0.2
* GitHub: https://github.com/tidyverse/ggplot2
* Source code: https://github.com/cran/ggplot2
* Date/Publication: 2026-02-03 08:50:23 UTC
* Number of recursive dependencies: 129

Run `revdepcheck::cloud_details(, "ggplot2")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Complete output:
      > library(testthat)
      > library(ggplot2)
      > 
      > test_check("ggplot2")
      Saving _problems/test-plot-4.R
      [ FAIL 1 | WARN 0 | SKIP 270 | PASS 1777 ]
      
    ...
      'geom-dotplot/bin-y-dodged-coord-flip.svg', 'geom-dotplot/bin-y-dodged.svg',
      'geom-dotplot/bin-y-dodging-3-stackgroups-histodot.svg',
      'geom-dotplot/bin-y-three-x-groups-bins-aligned-across-groups.svg',
      'geom-dotplot/bin-y-three-x-groups-bins-aligned-coord-flip.svg',
      'geom-dotplot/bin-y-three-x-groups-fill-and-dodge.svg', …,
      'theme/vertical-legends-placed-apart.svg', and
      'theme/width-is-3-times-height.svg'
      Error:
      ! Test failures.
      Execution halted
    ```

## In both

*   checking package dependencies ... NOTE
    ```
    Package which this enhances but not available for checking: ‘sp’
    ```

*   checking installed package size ... NOTE
    ```
      installed size is 14.6Mb
      sub-directories of 1Mb or more:
        R      3.5Mb
        data   1.5Mb
        doc    7.6Mb
        help   1.7Mb
    ```

# sourcoise

<details>

* Version: 1.1.0
* GitHub: https://github.com/xtimbeau/sourcoise
* Source code: https://github.com/cran/sourcoise
* Date/Publication: 2026-01-07 19:50:02 UTC
* Number of recursive dependencies: 69

Run `revdepcheck::cloud_details(, "sourcoise")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘sourcoise-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: sourcoise
    > ### Title: sources R script and caches results on disk
    > ### Aliases: sourcoise
    > 
    > ### ** Examples
    > 
    > ## Don't show: 
    ...
    > fs::file_copy(fs::path_package("sourcoise", "some_data.R"), dir, overwrite = TRUE)
    > bench::mark(forced = data <- sourcoise("some_data.R", force_exec = TRUE), 
    +     cached = data <- sourcoise("some_data.R"), max_iterations = 1)
    Error: ℹ In index: 1.
    ℹ With name: timing.
    Caused by error in `dplyr::rename()`:
    ! Names can't be of the form `...` or `..j`.
    ✖ These names are invalid:
      * "..2" at location 1.
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Complete output:
      > # This file is part of the standard setup for testthat.
      > # It is recommended that you do not modify it.
      > #
      > # Where should you do additional test configuration?
      > # Learn more about the roles of various files in:
      > # * https://r-pkgs.org/testing-design.html#sec-tests-files-overview
      > # * https://testthat.r-lib.org/articles/special-files.html
    ...
      i With name: timing.
      Caused by error in `dplyr::rename()`:
      ! Names can't be of the form `...` or `..j`.
      x These names are invalid:
        * "..2" at location 1.
      
      [ FAIL 4 | WARN 0 | SKIP 0 | PASS 18 ]
      Error:
      ! Test failures.
      Execution halted
    ```

