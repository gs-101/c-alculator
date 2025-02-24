(define-module (guix)
  #:use-module (guix packages)
  #:use-module (guix build-system gnu)
  #:use-module ((guix licenses) #:prefix license:)
  #:use-module (gnu packages version-control)
  #:use-module (gnu packages bash)
  #:use-module (gnu packages cpp)
  #:use-module (gnu packages gcc)
  #:use-module (gnu packages base)
  #:use-module (gnu packages shellutils)
  #:use-module (guix git-download)
  #:use-module (guix build utils)
  #:use-module (guix gexp))

(define-public c-alculator
  (package
   (name "c-alculator")
   (version "2.0.0")
   (source (origin
            (method git-fetch)
            (uri (git-reference
                  (url "https://github.com/gs-101/c-alculator")
                  (commit version)))
            (file-name (git-file-name name version))
            (sha256
             (base32
              "07ib5b9mqnv6kw5n8698y53pjsrwvqq15l8pxqjbg8l5a3s7zrhq"))))
   (build-system gnu-build-system)
   (arguments
    ;; Has an interactive test.
    (list #:tests? #f
          #:phases #~(modify-phases %standard-phases
                                    (delete 'configure))
          #:make-flags #~(list "CC=gcc"
                               "CFLAGS = -O2"
                               (string-append "PREFIX = " #$output))))
   (native-inputs
    (list git
          gnu-make))
   (inputs
    (list bash-minimal
          ;; Language server.
          ccls
          gcc
          direnv))
   (synopsis "Simple calculator written in C")
   (description
    "Simple calculator project written in C.  Has many faults, such as
using a regular number type for calculations.  This is only a learning
project")
   (home-page "https://github.com/gs-101/c-alculator")
   (license license:gpl3)))
