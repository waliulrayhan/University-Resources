<?php
require 'config/database.php';

// make sure edit post button was clicked
if (isset($_POST['submit'])) {
    // $id = filter_var($_POST['id'], FILTER_SANITIZE_NUMBER_INT);
    $previous_picture_name = filter_var($_POST['previous_picture_name'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $userid = filter_var($_POST['userid'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $firstname = filter_var($_POST['firstname'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $lastname = filter_var($_POST['lastname'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $email = filter_var($_POST['email'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $oldpassword = filter_var($_POST['oldpassword'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $newpassword = filter_var($_POST['newpassword'], FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    $picture = $_FILES['picture'];


    // check and validate input values
    if (!$firstname) {
        $_SESSION['edit-post'] = "Couldn't update profile. Invalid form data on edit profile page";
    } elseif (!$lastname) {
        $_SESSION['edit-post'] = "Couldn't update profile. Invalid form data on edit profile page";
    } elseif (!$email) {
        $_SESSION['edit-post'] = "Couldn't update profile. Invalid form data on edit profile page";
        // } elseif (!$oldpassword) {
        //     $_SESSION['edit-post'] = "Couldn't update profile. Invalid form data on edit profile page";
        // } elseif (!$newpassword) {
        //     $_SESSION['edit-post'] = "Couldn't update profile. Invalid form data on edit profile page";
        // 
    } elseif ($oldpassword=='' and $newpassword=='') {
        // delete existing picture if new picture is available
        if ($picture['name']) {
            $previous_picture_path = '../images/' . $previous_picture_name;
            if ($previous_picture_path) {
                unlink($previous_picture_path);
            }

            // WORK ON NEW picture
            // rename image
            $time = time(); // make each image name upload unique using current timestamp
            $picture_name = $time . $picture['name'];
            $picture_tmp_name = $picture['tmp_name'];
            $picture_destination_path = '../images/' . $picture_name;

            //make sure file is an image
            $allowed_files = ['png', 'jpg', 'jpeg'];
            $extension = explode('.', $picture_name);
            $extension = end($extension);
            if (in_array($extension, $allowed_files)) {
                // make sure picture is not too large (2 MB+)
                if ($picture['size'] < 2000000) {
                    // upload picture
                    move_uploaded_file($picture_tmp_name, $picture_destination_path);
                } else {
                    $_SESSION['edit-post'] = "Couldn't update profile. picture size is too large, should be less than 2 MB";
                }
            } else {
                $_SESSION['edit-post'] = "Couldn't update profile. picture should be png jpg or jpeg";
            }
        }



        // fetch user from database
        $fetch_user_query = "SELECT * FROM usermanagement WHERE userid='$userid'";

        $fetch_user_result = mysqli_query($connection, $fetch_user_query);

        if (mysqli_num_rows($fetch_user_result) == 1) {
            // convert the record into assoc array
            // $user_record = mysqli_fetch_assoc($fetch_user_result);
            // $db_password = $user_record['password'];

            // compare form password with database password
            // if (password_verify($oldpassword, $db_password)) {
            // set picture name if a new one was uploaded, else keep the old picture name
            $picture_to_insert = $picture_name ?? $previous_picture_name;

            // hash password
            // $hashed_password = password_hash($newpassword, PASSWORD_DEFAULT);

            $query = "UPDATE usermanagement SET firstname='$firstname', lastname='$lastname', picture='$picture_to_insert', email='$email' WHERE userid='$userid' LIMIT 1";
            $result = mysqli_query($connection, $query);
            // } else {
            //     $_SESSION['edit-post'] = "Your provide input does not match your old password.";
            // }
        }
    } else {
        // delete existing picture if new picture is available
        if ($picture['name']) {
            $previous_picture_path = '../images/' . $previous_picture_name;
            if ($previous_picture_path) {
                unlink($previous_picture_path);
            }

            // WORK ON NEW picture
            // rename image
            $time = time(); // make each image name upload unique using current timestamp
            $picture_name = $time . $picture['name'];
            $picture_tmp_name = $picture['tmp_name'];
            $picture_destination_path = '../images/' . $picture_name;

            //make sure file is an image
            $allowed_files = ['png', 'jpg', 'jpeg'];
            $extension = explode('.', $picture_name);
            $extension = end($extension);
            if (in_array($extension, $allowed_files)) {
                // make sure picture is not too large (2 MB+)
                if ($picture['size'] < 2000000) {
                    // upload picture
                    move_uploaded_file($picture_tmp_name, $picture_destination_path);
                } else {
                    $_SESSION['edit-post'] = "Couldn't update profile. picture size is too large, should be less than 2 MB";
                }
            } else {
                $_SESSION['edit-post'] = "Couldn't update profile. picture should be png jpg or jpeg";
            }
        }

        // fetch user from database
        $fetch_user_query = "SELECT * FROM usermanagement WHERE userid='$userid'";

        $fetch_user_result = mysqli_query($connection, $fetch_user_query);

        if (mysqli_num_rows($fetch_user_result) == 1) {
            // convert the record into assoc array
            $user_record = mysqli_fetch_assoc($fetch_user_result);
            $db_password = $user_record['password'];

            // compare form password with database password
            if (password_verify($oldpassword, $db_password)) {
                // set picture name if a new one was uploaded, else keep the old picture name
                $picture_to_insert = $picture_name ?? $previous_picture_name;

                // hash password
                $hashed_password = password_hash($newpassword, PASSWORD_DEFAULT);

                $query = "UPDATE usermanagement SET firstname='$firstname', lastname='$lastname', picture='$picture_to_insert', email='$email', password='$hashed_password' WHERE userid='$userid' LIMIT 1";
                $result = mysqli_query($connection, $query);
            } else {
                $_SESSION['edit-post'] = "Your provide input does not match your old password.";
            }
        }
    }




    if ($_SESSION['edit-post']) {
        // redirect to mannage form page if form was invalid
        header('location: ' . ROOT_URL . 'user/user-profile.php');
        die();
    }


    if (!mysqli_errno($connection)) {
        $_SESSION['edit-post-success'] = "Profile Updated successfully";
    }
}

header('location: ' . ROOT_URL . 'user/user-dashboard.php');
die();
