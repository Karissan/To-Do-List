(defun todo ()
  (let*  ((path  (if (< 1 (length *posix-argv*))
                     (second *posix-argv*)
                     "/home/karissan/.todo"))
          (data (with-open-file (file path :if-does-not-exist :create)
                 (loop for line = (read-line file nil) while line collect line))))
    (loop
      (format t "To-Do List~%")
      ;;Created something like a for loop (dotimes) that runs code with i as the nth time with the upper bound being length data
      (dotimes (i (length data))
        (let ((line (nth i data)))
          (format t "(~a) ~a~%" (1+ i) line)))
      (format t "~%To-Do List Menu~%")
      (format t "(a)dd~%")
      (format t "(d)elete~%")
      (format t "(q)uit~%")
      (format t "(s)ave~%")
      (format t "~%Select an option (remember to save before quitting): ")
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
         (loop
           (format t "Enter number or c to cancel: ")
           (let ((index (read)))
             (etypecase index
               (integer (if (< 0 index (1+ (length data)))
                            (progn
                              (setf data (append (subseq data 0 (1- index))
                                                 (subseq data index (length data))))
                              (return))
                            (format t "Invalid input~%"))
                )
               (symbol (if (eq index 'c)
                           (return))))
             )))
         (#\s
          (with-open-file (out path :direction :output :if-exists :supersede)
            (dolist (item data)
              (format out "~a~%" item))))
         (otherwise
          (format t "Error: Unknown option~%"))))))
(todo)
