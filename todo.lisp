(defun todo ()
  (let  ((data (with-open-file (file "/home/karissan/.todo")
                 (loop for line = (read-line file nil) while line collect line))))
    (loop
      (format t "To-Do List~%")
      ;;Created something like a for loop (dotimes) that runs code with i as the nth time with the upper bound being length data
      (dotimes (i (length data))
        (let ((line (nth i data)))
          (format t "(~a) ~a~%" i line)))
      (format t "~%To-Do List Menu~%")
      (format t "(a)dd~%")
      (format t "(q)uit~%")
      (format t "(s)ave~%")
      (format t "~%Select an option~%")
      ;;Prints out every item in To-Do list and will eventually apply code to every item
      (case (read-char)
        (#\q
         (return))
        (#\newline
         t)
        (#\a
         (read-char)
         (format t "Enter text: ")
         (setf data (append data (list (read-line)))))
        ;; Code to add an entry. Readline copies text input, list makes the input into a list which is then added to the old list (data) which then becomes the new list.
        (#\d
         (format t "Add later~%"))
        (#\s
         (format t "Add later~%"))
        (otherwise
         (format t "Error: Unknown option~%"))))))