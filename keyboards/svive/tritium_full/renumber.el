;; Emacs helper functions for writing g_led_config.

(defun renumber-region (beg end)
  (interactive "r")
  (goto-char beg)
  (let ((n 0))
    (while (re-search-forward "\\b\\([0-9]+\\)\\b" end)
      (replace-match (format "%d" n))
      (setq n (1+ n)))))

(defun x (mm)
  (interactive "nmm? ")
  (insert (format "%d" (round (* 224.0 (/ mm 412.0))))))
