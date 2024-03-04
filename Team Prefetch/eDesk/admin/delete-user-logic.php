<?php
require 'config/database.php';

if(isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);

    // fetch user from database
    $query = "SELECT * FROM usermanagement WHERE id=$id";
    $result = mysqli_query($connection, $query);
    $user = mysqli_fetch_assoc($result);

    // make sure we got back only one user
    if(mysqli_num_rows($result) == 1) {
        $picture_name = $user['picture'];
        $picture_path = '../images/' . $picture_name;

        // delete image if available
        if($picture_path) {
            unlink($picture_path);
        }
    }

    // fetch all pictures of user's posts and delete them
    $pictures_query = "SELECT picture FROM post WHERE user_id=$id";
    $pictures_result = mysqli_query($connection, $pictures_query);
    if(mysqli_num_rows($pictures_result) > 0) {
        while($picture = mysqli_fetch_assoc($pictures_result)) {
            $picture_path = '../images/' . $picture['picture'];
            // delete picture from images folder is exist
            if($picture_path) {
                unlink($picture_path);
            }
        }
    }

    // delete user from database
    $delete_user_query = "DELETE FROM usermanagement WHERE id=$id";
    $delete_user_result = mysqli_query($connection, $delete_user_query);
    if(mysqli_errno($connection)) {
        $_SESSION['delete-user'] = "Couldn't delete '{$user['firstname']} {$user['lastname']}'";
    } else {
        $_SESSION['delete-user-success'] = "User '{$user['firstname']} {$user['lastname']}' deleted successfully";
    }
}

header('location: ' . ROOT_URL . 'admin/admin-user-management.php');
die();