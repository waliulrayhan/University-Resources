<?php
require 'config/database.php';

if (isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);


    if (!mysqli_errno($connection)) {
        // delete category
        $query = "DELETE FROM adminaddoffice WHERE id=$id LIMIT 1";
        $result = mysqli_query($connection, $query);
        $_SESSION['delete-category-success'] = "Office deleted successfully";
    }

}
header('location: ' . ROOT_URL . 'admin/admin-manage-office.php');
die();
