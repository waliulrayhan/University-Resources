<?php
require 'config/database.php';

if(isset($_POST['submit'])) {
    $id = filter_var($_POST['id'], FILTER_SANITIZE_NUMBER_INT);
    $comment = filter_var($_POST['comment'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    // $description = filter_var($_POST['description'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);

    // validate inputs
    if(!$comment) {
        $_SESSION['no-comment'] = "Invalid form input or add comment";
    } else {
        $query = "UPDATE post SET comment='$comment' WHERE id='$id'";
        $result = mysqli_query($connection, $query);

        if(mysqli_errno($connection)) {
            $_SESSION['comment-no'] = "Couldn't add comment";
        } else {
            $_SESSION['comment-success'] = "Comment added successfully";
        }
    }
}

header('location: ' . ROOT_URL . 'admin/admin-index.php');
die();