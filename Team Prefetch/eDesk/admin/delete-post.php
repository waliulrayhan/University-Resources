<?php
require 'config/database.php';

if (isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);

    // fetch post from database in order to delete picture from images folder
    $query = "SELECT * FROM post WHERE id=$id";
    $result = mysqli_query($connection, $query);

    // make sure only 1 record / post was deleted
    if (mysqli_num_rows($result) == 1) {
        $post = mysqli_fetch_assoc($result);
        $picture_name = $post['picture'];
        $picture_path = '../images/' . $picture_name;

        if($picture_path) {
            unlink($picture_path);

            // delete post from database
            $delete_post_query = "DELETE FROM post WHERE id=$id LIMIT 1";
            $delete_post_result = mysqli_query($connection, $delete_post_query);

            if(!mysqli_errno($connection)) {
                $_SESSION['delete-post-success'] = "Post deleted successfully";
            }
        }
    }
}

header('location: ' . ROOT_URL . 'admin/admin-manage-post.php');
die();
