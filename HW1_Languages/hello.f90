! comments start with exclamation mark
PROGRAM HELLO
CHARACTER :: ARG*32                  ! legacy syntax for string
! CHARACTER(LEN = 32) :: ARG         ! newer preferred
! CHARACTER, DIMENSION(32) :: CARRAY ! this is an array of chars
PRINT *, 'Hello Fortran!'
! The famous Fortran DO loop, I is implicit integer because of the letter i
DO I = 1, IARGC()                    ! IARGC gets argc returns int
CALL GETARG(I, ARG)                  ! subroutine to put arg[i] in ARG
CALL GREET(ARG)
END DO
END

SUBROUTINE GREET(s)
CHARACTER :: s*32
! CHARACTER(LEN = *) :: s
PRINT *, 'Hello ' // s               ! // is string concatenation
END
