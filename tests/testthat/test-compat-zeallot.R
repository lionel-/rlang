
test_that("LHS must be a list of symbols wrapped in `c()`", {
  expect_error(
    foo %<-% list(1),
    "must be a call to `c()`",
    fixed = TRUE
  )

  expect_error(
    c(foo()) %<-% list(1),
    "Element 1 of the left-hand side .* must be a symbol"
  )
})

test_that("can assign lists and vectors", {
  c(foo, bar) %<-% list(a = 1, 2)
  expect_equal(list(foo, bar), list(1, 2))

  c(foo, bar) %<-% c(a = 1, 2)
  expect_equal(list(foo, bar), list(1, 2))
})

test_that("RHS and LHS must have the same length", {
  expect_error(
    c(foo) %<-% list(),
    "must be the same length"
  )

  expect_error(
    c(foo, bar) %<-% as.list(1:10),
    "must be the same length"
  )
})

test_that("can match by name", {
  local({
    c(foo = foo, bar = bar) %<-% list(bar = 2, foo = 1)
    expect_equal(list(foo, bar), list(1, 2))
  })

  local({
    c(FOO = foo, BAR = bar) %<-% list(bar = 2, foo = 1)
    expect_equal(list(FOO, BAR), list(1, 2))
  })

  local({
    c(FOO = foo, BAR = bar) %<-% list(3, bar = 2, 4, foo = 1, 5)
    expect_equal(list(FOO, BAR), list(1, 2))
  })

  local({
    c(foo = , bar = ) %<-% list(bar = 2, foo = 1)
    expect_equal(list(foo, bar), list(1, 2))
  })
})
