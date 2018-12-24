(defun todo ()
  (let  ((data (with-open-file (file "/home/karissan/.todo")
                 (loop for line = (read-line file nil) while line collect line))))
    (loop
      (case (read-char)
        (#\q
         (return))
        (#\newline
         t)
        (#\a
         (format t "Add later~%"))
        (otherwise
         (format t "Error: Unknown option~%"))))))
