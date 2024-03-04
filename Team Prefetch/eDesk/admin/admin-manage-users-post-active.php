<?php
require 'config/database.php';

if(isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);

    // fetch post from database
    $query = "SELECT * FROM post WHERE id=$id";
    $result = mysqli_query($connection, $query);
    $postv = mysqli_fetch_assoc($result);

    // make sure we got back only one post
    if(mysqli_num_rows($result) == 1) {

        $active_post_query = "UPDATE post SET status = 'Approved' WHERE id =$id";
    
        $active_post_result = mysqli_query($connection, $active_post_query);
        if(mysqli_errno($connection)) {
            $_SESSION['active-post'] = "Couldn't active post";
        } else {
            $_SESSION['active-post-success'] = "Post approved successfully";
        }
    }

}

header('location: ' . ROOT_URL . 'admin/admin-manage-users-post.php');
die();