# BasketballAnalyzeR

<details>

* Version: 0.5.0
* GitHub: https://github.com/sndmrc/BasketballAnalyzeR
* Source code: https://github.com/cran/BasketballAnalyzeR
* Date/Publication: 2020-06-26 09:00:11 UTC
* Number of recursive dependencies: 76

Run `cloud_details(, "BasketballAnalyzeR")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘BasketballAnalyzeR-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: scatterplot
    > ### Title: Draws a scatter plot or a matrix of scatter plots
    > ### Aliases: scatterplot
    > 
    > ### ** Examples
    > 
    > # Single scatter plot
    ...
     13.                   ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
     14.                   │ └─base::vapply(x, is.null, logical(1))
     15.                   └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     16.                     └─ggplot2:::FUN(X[[i]], ...)
     17.                       ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
     18.                       ├─tibble::as_tibble(vars)
     19.                       └─tibble:::as_tibble.list(vars)
     20.                         └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     21.                           └─tibble:::check_valid_cols(x)
    Execution halted
    ```

## In both

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘circlize’ ‘hexbin’ ‘scales’ ‘sna’
      All declared Imports should be used.
    ```

# bayesplot

<details>

* Version: 1.8.0
* GitHub: https://github.com/stan-dev/bayesplot
* Source code: https://github.com/cran/bayesplot
* Date/Publication: 2021-01-10 17:10:30 UTC
* Number of recursive dependencies: 157

Run `cloud_details(, "bayesplot")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘bayesplot-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: MCMC-diagnostics
    > ### Title: General MCMC diagnostics
    > ### Aliases: MCMC-diagnostics mcmc_rhat mcmc_rhat_hist mcmc_rhat_data
    > ###   mcmc_neff mcmc_neff_hist mcmc_neff_data mcmc_acf mcmc_acf_bar
    > 
    > ### ** Examples
    > 
    ...
     10.               ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
     11.               │ └─base::vapply(x, is.null, logical(1))
     12.               └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     13.                 └─ggplot2:::FUN(X[[i]], ...)
     14.                   ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
     15.                   ├─tibble::as_tibble(vars)
     16.                   └─tibble:::as_tibble.list(vars)
     17.                     └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     18.                       └─tibble:::check_valid_cols(x)
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
        7.           └─ggplot2:::f(...)
        8.             └─ggplot2::combine_vars(data, params$plot_env, rows, drop = params$drop)
        9.               ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
       10.               │ └─base::vapply(x, is.null, logical(1))
       11.               └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
       12.                 └─ggplot2:::FUN(X[[i]], ...)
       13.                   ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
       14.                   ├─tibble::as_tibble(vars)
       15.                   └─tibble:::as_tibble.list(vars)
       16.                     └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
       17.                       └─tibble:::check_valid_cols(x)
      
      [ FAIL 2 | WARN 0 | SKIP 40 | PASS 1003 ]
      Error: Test failures
      Execution halted
    ```

## In both

*   checking installed package size ... NOTE
    ```
      installed size is  5.9Mb
      sub-directories of 1Mb or more:
        R     1.8Mb
        doc   3.4Mb
    ```

# crosstable

<details>

* Version: 0.2.1
* GitHub: https://github.com/DanChaltiel/crosstable
* Source code: https://github.com/cran/crosstable
* Date/Publication: 2021-03-08 09:20:02 UTC
* Number of recursive dependencies: 126

Run `cloud_details(, "crosstable")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
       12.       │ │ └─base:::tryCatchList(expr, classes, parentenv, handlers)
       13.       │ │   └─base:::tryCatchOne(expr, names, parentenv, handlers[[1L]])
       14.       │ │     └─base:::doTryCatch(return(expr), name, parentenv, handler)
       15.       │ └─tidyselect:::instrument_base_errors(expr)
       16.       │   └─base::withCallingHandlers(...)
       17.       └─tidyselect:::vars_select_eval(...)
       18.         └─tidyselect:::walk_data_tree(expr, data_mask, context_mask)
       19.           └─tidyselect:::eval_c(expr, data_mask, context_mask)
       20.             └─tidyselect:::reduce_sels(node, data_mask, context_mask, init = init)
       21.               └─tidyselect:::walk_data_tree(new, data_mask, context_mask)
       22.                 └─tidyselect:::stop_formula(expr)
      
      [ FAIL 2 | WARN 0 | SKIP 15 | PASS 327 ]
      Error: Test failures
      Execution halted
    ```

## In both

*   checking examples ... ERROR
    ```
    Running examples in ‘crosstable-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: as_gt.crosstable
    > ### Title: Converts a 'crosstable' object into a formatted 'gt' table.
    > ### Aliases: as_gt.crosstable as_gt as_gt.default
    > 
    > ### ** Examples
    > 
    > xx = mtcars2 %>% dplyr::select(1:9)
    > crosstable(xx) %>% as_gt
    Error: Package "gt" is obviously needed for function as_gt() to work. Please install it.
    Backtrace:
        █
     1. ├─crosstable(xx) %>% as_gt
     2. └─crosstable::as_gt(.)
    Execution halted
    ```

# DeclareDesign

<details>

* Version: 0.26.0
* GitHub: https://github.com/DeclareDesign/DeclareDesign
* Source code: https://github.com/cran/DeclareDesign
* Date/Publication: 2021-02-14 21:50:10 UTC
* Number of recursive dependencies: 146

Run `cloud_details(, "DeclareDesign")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
             design  ATE_positive       estimator    Z        <NA>      5  -0.26018
                                                                          (0.18684)
      ══ Skipped tests ═══════════════════════════════════════════════════════════════
      ● On CRAN (4)
      ● Skipped bootstrap SE test for speed (1)
      ● empty test (2)
      
      ══ Failed tests ════════════════════════════════════════════════════════════════
      ── Failure (test-design-summary.R:34:3): Basic design summary ──────────────────
      s$formulae[[8]] not equal to Y ~ Z.
      target is NULL, current is formula
      
      [ FAIL 1 | WARN 0 | SKIP 7 | PASS 498 ]
      Error: Test failures
      Execution halted
    ```

# dplyr

<details>

* Version: 1.0.5
* GitHub: https://github.com/tidyverse/dplyr
* Source code: https://github.com/cran/dplyr
* Date/Publication: 2021-03-05 11:00:02 UTC
* Number of recursive dependencies: 81

Run `cloud_details(, "dplyr")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      ── Error (test-case-when.R:130:5): can pass unevaluated formulas to case_when() ──
      Error: Case 1 (`!!!fs`) must be a two-sided formula, not a call.
      Backtrace:
          █
       1. └─base::eval(...)
       2.   └─base::eval(...)
       3.     └─dplyr::case_when(!!!fs) test-case-when.R:130:4
       4.       └─dplyr:::map2(...)
       5.         └─base::mapply(.f, .x, .y, MoreArgs = list(...), SIMPLIFY = FALSE)
       6.           └─(function (x, i, default_env, dots_env) ...
       7.             └─dplyr:::abort_case_when_formula(arg, i, x)
      
      [ FAIL 3 | WARN 0 | SKIP 57 | PASS 1915 ]
      Error: Test failures
      Execution halted
    ```

## In both

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 4 marked UTF-8 strings
    ```

# gestalt

<details>

* Version: 0.1.8
* GitHub: https://github.com/egnha/gestalt
* Source code: https://github.com/cran/gestalt
* Date/Publication: 2019-06-27 08:20:03 UTC
* Number of recursive dependencies: 50

Run `cloud_details(, "gestalt")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘gestalt-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: fn
    > ### Title: Function Declarations with Quasiquotation
    > ### Aliases: fn fn_
    > 
    > ### ** Examples
    > 
    > fn(x ~ x + 1)
    Error: Final argument must be a formula (specifying the body)
    Execution halted
    ```

## In both

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Complete output:
      > library(testthat)
      > library(gestalt)
      > 
      > test_check("gestalt")
      Error in loadNamespace(name) : there is no package called 'withr'
      Calls: test_check ... loadNamespace -> withRestarts -> withOneRestart -> doWithOneRestart
      Execution halted
    ```

# GGally

<details>

* Version: 2.1.1
* GitHub: https://github.com/ggobi/ggally
* Source code: https://github.com/cran/GGally
* Date/Publication: 2021-03-08 06:00:03 UTC
* Number of recursive dependencies: 137

Run `cloud_details(, "GGally")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘GGally-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: +.gg
    > ### Title: Modify a 'ggmatrix' object by adding an 'ggplot2' object to all
    > ###   plots
    > ### Aliases: +.gg add_to_ggmatrix
    > 
    > ### ** Examples
    > 
    ...
     13.                   ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
     14.                   │ └─base::vapply(x, is.null, logical(1))
     15.                   └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     16.                     └─ggplot2:::FUN(X[[i]], ...)
     17.                       ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
     18.                       ├─tibble::as_tibble(vars)
     19.                       └─tibble:::as_tibble.list(vars)
     20.                         └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     21.                           └─tibble:::check_valid_cols(x)
    Execution halted
    ```

# incase

<details>

* Version: 0.2.1
* GitHub: https://github.com/rossellhayes/incase
* Source code: https://github.com/cran/incase
* Date/Publication: 2021-01-14 21:50:03 UTC
* Number of recursive dependencies: 53

Run `cloud_details(, "incase")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      ── Error (test-in_case.R:189:5): can pass unevaluated formulas to in_case() ────
      Error: `sep` must be a character string
      Backtrace:
          █
       1. └─base::eval(...)
       2.   └─base::eval(...)
       3.     └─incase::in_case(!!!fs) test-in_case.R:189:4
       4.       ├─incase:::glubort(...)
       5.       │ └─base:::glue(..., .sep = " ")
       6.       └─plu::stick(nfs, code, max = 5)
       7.         └─plu:::validate_sep(sep)
      
      [ FAIL 3 | WARN 0 | SKIP 0 | PASS 71 ]
      Error: Test failures
      Execution halted
    ```

# interactions

<details>

* Version: 1.1.3
* GitHub: https://github.com/jacob-long/interactions
* Source code: https://github.com/cran/interactions
* Date/Publication: 2020-04-04 14:30:02 UTC
* Number of recursive dependencies: 144

Run `cloud_details(, "interactions")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘interactions-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: cat_plot
    > ### Title: Plot interaction effects between categorical predictors.
    > ### Aliases: cat_plot
    > 
    > ### ** Examples
    > 
    > 
    ...
      4. ggplot2:::ggplot_build.ggplot(x)
      5. layout$setup(data, plot$data, plot$plot_env)
      6. ggplot2:::f(..., self = self)
         ...
     12. base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     13. ggplot2:::FUN(X[[i]], ...)
     16. tibble:::as_tibble.list(vars)
     17. tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     18. tibble:::check_valid_cols(x)
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
       12.                 └─ggplot2:::f(...)
       13.                   └─ggplot2::combine_vars(data, params$plot_env, rows, drop = params$drop)
       14.                     ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
       15.                     │ └─base::vapply(x, is.null, logical(1))
       16.                     └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
       17.                       └─ggplot2:::FUN(X[[i]], ...)
       18.                         ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
       19.                         ├─tibble::as_tibble(vars)
       20.                         └─tibble:::as_tibble.list(vars)
       21.                           └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
       22.                             └─tibble:::check_valid_cols(x)
      
      [ FAIL 13 | WARN 0 | SKIP 45 | PASS 53 ]
      Error: Test failures
      Execution halted
    ```

## In both

*   checking package dependencies ... NOTE
    ```
    Packages which this enhances but not available for checking:
      'brms', 'rstanarm'
    ```

*   checking Rd cross-references ... NOTE
    ```
    Packages unavailable to check Rd xrefs: ‘quantreg’, ‘brms’, ‘effects’, ‘Hmisc’, ‘rockchalk’, ‘pequod’
    ```

# mosaicCore

<details>

* Version: 0.9.0
* GitHub: https://github.com/ProjectMOSAIC/mosaicCore
* Source code: https://github.com/cran/mosaicCore
* Date/Publication: 2021-01-16 08:00:03 UTC
* Number of recursive dependencies: 98

Run `cloud_details(, "mosaicCore")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘mosaicCore-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: df_stats
    > ### Title: Calculate statistics for "response" variables
    > ### Aliases: df_stats
    > 
    > ### ** Examples
    > 
    > df_stats( ~ hp, data = mtcars)
    ...
    3       hp   8    3 194.1667  180.0     150     245
    4       hp   4    4  76.0000   66.0      52     109
    5       hp   6    4 116.5000  116.5     110     123
    6       hp   4    5 102.0000  102.0      91     113
    7       hp   6    5 175.0000  175.0     175     175
    8       hp   8    5 299.5000  299.5     264     335
    > df_stats( hp ~ cyl, groups = ~gear, data = mtcars, mean, median, range)
    Error in terms.formula(formula, data = data) : invalid model formula
    Calls: df_stats ... model.frame -> model.frame.default -> terms -> terms.formula
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
           █
        1. ├─testthat::expect_equivalent(...) test-tally.R:84:2
        2. │ └─testthat::quasi_label(enquo(expected), expected.label, arg = "expected")
        3. │   └─rlang::eval_bare(expr, quo_get_env(quo))
        4. ├─mosaicCore::tally(sex ~ homeless, groups = ~substance, data = mosaicData::HELPrct)
        5. └─mosaicCore:::mosaic_tally.formula(...)
        6.   └─mosaicCore::evalFormula(formula, data)
        7.     └─mosaicCore::evalSubFormula(...)
        8.       └─base::data.frame(eval(x, data, env), stringsAsFactors = FALSE)
        9.         ├─base::as.data.frame(x[[i]], optional = TRUE)
       10.         └─base::as.data.frame.default(x[[i]], optional = TRUE)
      
      [ FAIL 2 | WARN 0 | SKIP 0 | PASS 78 ]
      Error: Test failures
      Execution halted
    ```

# MPTmultiverse

<details>

* Version: 0.4-2
* GitHub: https://github.com/mpt-network/MPTmultiverse
* Source code: https://github.com/cran/MPTmultiverse
* Date/Publication: 2020-06-24 09:40:11 UTC
* Number of recursive dependencies: 91

Run `cloud_details(, "MPTmultiverse")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘MPTmultiverse-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: fit_mpt
    > ### Title: Multiverse Analysis for MPT Models
    > ### Aliases: fit_mpt
    > 
    > ### ** Examples
    > 
    > 
    ...
     10.               ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
     11.               │ └─base::vapply(x, is.null, logical(1))
     12.               └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     13.                 └─ggplot2:::FUN(X[[i]], ...)
     14.                   ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
     15.                   ├─tibble::as_tibble(vars)
     16.                   └─tibble:::as_tibble.list(vars)
     17.                     └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     18.                       └─tibble:::check_valid_cols(x)
    Execution halted
    ```

## In both

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
        2.   └─TreeBUGS::readEQN
        3.     └─base::getExportedValue(pkg, name)
        4.       └─base::asNamespace(ns)
        5.         └─base::getNamespace(ns)
        6.           └─base::loadNamespace(name)
        7.             ├─base::namespaceImportFrom(...)
        8.             │ └─base::asNamespace(ns)
        9.             └─base::loadNamespace(j <- i[[1L]], c(lib.loc, .libPaths()), versionCheck = vI[[j]])
       10.               └─base::withRestarts(stop(cond), retry_loadNamespace = function() NULL)
       11.                 └─base:::withOneRestart(expr, restarts[[1L]])
       12.                   └─base:::doWithOneRestart(return(expr), restart)
      
      [ FAIL 2 | WARN 0 | SKIP 4 | PASS 6 ]
      Error: Test failures
      Execution halted
    ```

# nofrills

<details>

* Version: 0.3.1
* GitHub: https://github.com/egnha/nofrills
* Source code: https://github.com/cran/nofrills
* Date/Publication: 2021-01-08 19:50:05 UTC
* Number of recursive dependencies: 38

Run `cloud_details(, "nofrills")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘nofrills-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: as_fn
    > ### Title: Abbreviated functional arguments
    > ### Aliases: as_fn
    > 
    > ### ** Examples
    > 
    > call_fn <- function(.f, x) {
    ...
     1. ├─global::call_fn(.(. ~ sin(.)^2), 1)
     2. │ └─nofrills::as_fn(.f)
     3. │   └─nofrills:::interpret_fn(x, match.fun(.f), parent.frame(2))
     4. │     └─base::eval(x, env)
     5. │       └─base::eval(x, env)
     6. └─(function (..., ..env = parent.frame()) ...
     7.   └─nofrills:::get_fn_declaration(...)
     8.     └─nofrills:::get_exprs(...)
     9.       └─nofrills:::validate(exprs_(...))
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
       2.   └─nofrills:::get_fn_declaration(...)
       3.     └─nofrills:::get_exprs(...)
       4.       └─nofrills:::validate(exprs_(...))
      ── Error (???): function body can be unquoted ──────────────────────────────────
      Error: Final argument must be a formula (specifying the body)
      Backtrace:
          █
       1. └─(function (..., ..env = parent.frame()) ...
       2.   └─nofrills:::get_fn_declaration(...)
       3.     └─nofrills:::get_exprs(...)
       4.       └─nofrills:::validate(exprs_(...))
      
      [ FAIL 37 | WARN 0 | SKIP 0 | PASS 41 ]
      Error: Test failures
      Execution halted
    ```

# plotly

<details>

* Version: 4.9.3
* GitHub: https://github.com/ropensci/plotly
* Source code: https://github.com/cran/plotly
* Date/Publication: 2021-01-10 14:30:02 UTC
* Number of recursive dependencies: 161

Run `cloud_details(, "plotly")` for more info

</details>

## Newly broken

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
       14.                   └─ggplot2:::f(...)
       15.                     └─ggplot2::combine_vars(data, params$plot_env, rows, drop = params$drop)
       16.                       ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
       17.                       │ └─base::vapply(x, is.null, logical(1))
       18.                       └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
       19.                         └─ggplot2:::FUN(X[[i]], ...)
       20.                           ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
       21.                           ├─tibble::as_tibble(vars)
       22.                           └─tibble:::as_tibble.list(vars)
       23.                             └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
       24.                               └─tibble:::check_valid_cols(x)
      
      [ FAIL 3 | WARN 60 | SKIP 56 | PASS 1384 ]
      Error: Test failures
      Execution halted
    ```

## In both

*   checking installed package size ... NOTE
    ```
      installed size is  7.0Mb
      sub-directories of 1Mb or more:
        htmlwidgets   3.8Mb
    ```

# radiant.data

<details>

* Version: 1.3.12
* GitHub: https://github.com/radiant-rstats/radiant.data
* Source code: https://github.com/cran/radiant.data
* Date/Publication: 2020-11-27 05:30:02 UTC
* Number of recursive dependencies: 157

Run `cloud_details(, "radiant.data")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘radiant.data-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: plot.pivotr
    > ### Title: Plot method for the pivotr function
    > ### Aliases: plot.pivotr
    > 
    > ### ** Examples
    > 
    > pivotr(diamonds, cvars = "cut") %>% plot()
    ...
     10.               ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
     11.               │ └─base::vapply(x, is.null, logical(1))
     12.               └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     13.                 └─ggplot2:::FUN(X[[i]], ...)
     14.                   ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
     15.                   ├─tibble::as_tibble(vars)
     16.                   └─tibble:::as_tibble.list(vars)
     17.                     └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     18.                       └─tibble:::check_valid_cols(x)
    Execution halted
    ```

# RTL

<details>

* Version: 0.1.5
* GitHub: https://github.com/risktoollib/RTL
* Source code: https://github.com/cran/RTL
* Date/Publication: 2020-11-11 06:20:02 UTC
* Number of recursive dependencies: 151

Run `cloud_details(, "RTL")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘RTL-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: stl_decomp
    > ### Title: 'stl_decomp'
    > ### Aliases: stl_decomp
    > 
    > ### ** Examples
    > 
    > x <- dflong %>% dplyr::filter(series=="CL01")
    ...
     10.               ├─ggplot2:::compact(lapply(data, eval_facets, facets = vars, possible_columns = possible_columns))
     11.               │ └─base::vapply(x, is.null, logical(1))
     12.               └─base::lapply(data, eval_facets, facets = vars, possible_columns = possible_columns)
     13.                 └─ggplot2:::FUN(X[[i]], ...)
     14.                   ├─ggplot2:::new_data_frame(tibble::as_tibble(vars))
     15.                   ├─tibble::as_tibble(vars)
     16.                   └─tibble:::as_tibble.list(vars)
     17.                     └─tibble:::lst_to_tibble(x, .rows, .name_repair, col_lengths(x))
     18.                       └─tibble:::check_valid_cols(x)
    Execution halted
    ```

## In both

*   checking installed package size ... NOTE
    ```
      installed size is  6.1Mb
      sub-directories of 1Mb or more:
        data   5.9Mb
    ```

*   checking dependencies in R code ... NOTE
    ```
    Namespaces in Imports field not imported from:
      ‘quantmod’ ‘sp’ ‘timetk’
      All declared Imports should be used.
    ```

*   checking data for non-ASCII characters ... NOTE
    ```
      Note: found 688 marked UTF-8 strings
    ```

# ruler

<details>

* Version: 0.2.4
* GitHub: https://github.com/echasnovski/ruler
* Source code: https://github.com/cran/ruler
* Date/Publication: 2020-11-25 08:00:03 UTC
* Number of recursive dependencies: 61

Run `cloud_details(, "ruler")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘ruler-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: rules
    > ### Title: Create a list of rules
    > ### Aliases: rules
    > 
    > ### ** Examples
    > 
    > if (utils::packageVersion("dplyr") < "0.8.0") {
    ...
      4. │   └─dplyr:::summarise_cols(.data, ...)
      5. │     ├─base::withCallingHandlers(...)
      6. │     └─mask$eval_all_summarise(quo)
      7. ├─dplyr:::abort_glue(character(0), list(result = ~sd(.)), "dplyr:::summarise_unsupported_type")
      8. │ ├─rlang::exec(abort, class = class, !!!data)
      9. │ └─(function (message = NULL, class = NULL, ..., trace = NULL, parent = NULL, ...
     10. │   └─rlang:::signal_abort(cnd)
     11. │     └─base::signalCondition(cnd)
     12. └─(function (e) ...
    Execution halted
    ```

# table.express

<details>

* Version: 0.3.1
* GitHub: https://github.com/asardaes/table.express
* Source code: https://github.com/cran/table.express
* Date/Publication: 2019-09-07 11:10:02 UTC
* Number of recursive dependencies: 53

Run `cloud_details(, "table.express")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘table.express-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: filter_sd
    > ### Title: Filter subset of data
    > ### Aliases: filter_sd filter_sd.ExprBuilder filter_sd.data.table
    > 
    > ### ** Examples
    > 
    > 
    > data("mtcars")
    > 
    > data.table::as.data.table(mtcars) %>%
    +     filter_sd(c("vs", "am"), ~ .x == 1)
    Error: operations are possible only for numeric, logical or complex types
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
      Backtrace:
          █
       1. ├─table.express::filter_sd(DT, ~grepl("t$", .y), ~.x > 3)
       2. └─table.express:::filter_sd.data.table(...)
       3.   └─table.express:::filter_sd.ExprBuilder(eb, ..., .caller_env_n = 2L)
       4.     ├─base::Map(substitue_col_pronoun, list(.how), rlang::syms(.SDcols))
       5.     │ └─base::mapply(FUN = f, ..., SIMPLIFY = FALSE)
       6.     └─rlang::syms(.SDcols)
       7.       └─rlang:::map(x, sym)
       8.         └─base::lapply(.x, .f, ...)
       9.           └─rlang:::FUN(X[[i]], ...)
      
      [ FAIL 3 | WARN 0 | SKIP 1 | PASS 593 ]
      Error: Test failures
      Execution halted
    ```

# tsibble

<details>

* Version: 1.0.0
* GitHub: https://github.com/tidyverts/tsibble
* Source code: https://github.com/cran/tsibble
* Date/Publication: 2021-02-20 23:00:02 UTC
* Number of recursive dependencies: 92

Run `cloud_details(, "tsibble")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘tsibble-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: index_by
    > ### Title: Group by time index and collapse with 'summarise()'
    > ### Aliases: index_by
    > 
    > ### ** Examples
    > 
    > pedestrian %>% index_by()
    ...
      3. ├─tsibble::index_by(., Year_Month = ~yearmonth(.))
      4. ├─tsibble:::index_by.tbl_ts(., Year_Month = ~yearmonth(.))
      5. │ ├─dplyr::mutate(ungrp, `:=`(!!idx2, !!expr))
      6. │ └─dplyr:::mutate.data.frame(ungrp, `:=`(!!idx2, !!expr))
      7. │   └─dplyr:::mutate_cols(.data, ...)
      8. │     ├─base::withCallingHandlers(...)
      9. │     └─mask$eval_all_mutate(quo)
     10. └─dplyr:::abort_glue(...)
     11.   └─rlang::exec(abort, class = class, !!!data)
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘spelling.R’
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
        3. │   └─rlang::eval_bare(expr, quo_get_env(quo))
        4. ├─pedestrian %>% index_by(yrmth = ~yearmonth(.))
        5. ├─tsibble::index_by(., yrmth = ~yearmonth(.))
        6. ├─tsibble:::index_by.tbl_ts(., yrmth = ~yearmonth(.))
        7. │ ├─dplyr::mutate(ungrp, `:=`(!!idx2, !!expr))
        8. │ └─dplyr:::mutate.data.frame(ungrp, `:=`(!!idx2, !!expr))
        9. │   └─dplyr:::mutate_cols(.data, ...)
       10. │     ├─base::withCallingHandlers(...)
       11. │     └─mask$eval_all_mutate(quo)
       12. └─dplyr:::abort_glue(...)
       13.   └─rlang::exec(abort, class = class, !!!data)
      
      [ FAIL 1 | WARN 15 | SKIP 5 | PASS 742 ]
      Error: Test failures
      Execution halted
    ```

# xpose

<details>

* Version: 0.4.12
* GitHub: https://github.com/UUPharmacometrics/xpose
* Source code: https://github.com/cran/xpose
* Date/Publication: 2021-01-12 16:50:02 UTC
* Number of recursive dependencies: 98

Run `cloud_details(, "xpose")` for more info

</details>

## Newly broken

*   checking examples ... ERROR
    ```
    Running examples in ‘xpose-Ex.R’ failed
    The error most likely occurred in:
    
    > ### Name: get_prm
    > ### Title: Access model parameters
    > ### Aliases: get_prm
    > 
    > ### ** Examples
    > 
    > # Store the parameter table
    > prm <- get_prm(xpdb_ex_pk, .problem = 1)
    Returning parameter estimates from $prob no.1, subprob no.0, method foce
    Error: Argument `formula` needs to be a formula
    Execution halted
    ```

*   checking tests ... ERROR
    ```
      Running ‘testthat.R’
    Running the tests in ‘tests/testthat.R’ failed.
    Last 13 lines of output:
           █
        1. ├─xpose::get_prm(xpdb_ex_pk, transform = TRUE, quiet = TRUE) test-xpdb_access.R:163:2
        2. │ └─`%>%`(...)
        3. ├─purrr::map(...)
        4. │ └─xpose:::.f(.x[[i]], ...)
        5. │   ├─`%>%`(...)
        6. │   └─purrr::map_df(...)
        7. │     └─purrr::map(.x, .f, ...)
        8. │       └─xpose:::.f(.x[[i]], ...)
        9. │         └─xpose::transform_prm(.x, mu = prm_mean, sigma = prm_cov, method = "delta")
       10. └─dplyr::mutate(., se = sqrt(.$variance))
      
      [ FAIL 3 | WARN 0 | SKIP 7 | PASS 512 ]
      Error: Test failures
      Execution halted
    ```

