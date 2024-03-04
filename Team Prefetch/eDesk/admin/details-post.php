<?php
include 'partials/header.php';

// get back form data if invalid
$comment = $_SESSION['comment']['comment'] ?? null;

// fetch post from database if id is set
if (isset($_GET['id'])) {
    $id = filter_var($_GET['id'], FILTER_SANITIZE_NUMBER_INT);
    $query = "SELECT * FROM post WHERE id=$id";
    $result = mysqli_query($connection, $query);
    $post = mysqli_fetch_assoc($result);
} else {
    header('location: ' . ROOT_URL . 'admin/admin-index.php');
    die();
}
?>


<section class="singlepost">
    <div class="container singlepost__container">
        <div class="post__info">
            <?php if ($post['user_id']) : ?>
                <?php
                // fetch category from categories table using category_id of post
                $category_id = $post['office_id'];
                $category_query = "SELECT * FROM adminaddoffice WHERE id=$category_id";
                $category_result = mysqli_query($connection, $category_query);
                $category = mysqli_fetch_assoc($category_result);
                ?>
                <h3><?= $post['type'] ?><?= $post['id'] ?></h3>
                <a href="<?= ROOT_URL ?>admin/admin-catagory-post.php?id=<?= $post['office_id'] ?>" class="category__button"><?= $category['title'] ?></a>

                <div class="post__author">
                    <?php
                    // fetch user from users table using user_id
                    $user_id = $post['user_id'];
                    $user_query = "SELECT * FROM usermanagement WHERE id=$user_id";
                    $user_result = mysqli_query($connection, $user_query);
                    $user = mysqli_fetch_assoc($user_result);
                    ?>
                    <div class="post__author-avatar">
                        <img src="<?= ROOT_URL . 'images/' . $user['picture'] ?>">
                    </div>
                    <div class="post__author-info">
                        <h5>By: <?= "{$user['firstname']} {$user['lastname']}" ?></h5>
                        <small>
                            <?= date("M d, Y - H:i", strtotime($post['date_time'])) ?>
                        </small>
                    </div>
                </div>

                </br>
                <div class="singlepost__thumbnail">
                    <!-- <img src="./images/<?= $post['picture'] ?>"> -->
                    <img src="<?= ROOT_URL . 'images/' . $post['picture'] ?>">
                </div>
                <p class="post__body">
                    <?= $post['body'] ?>
                </p>
                </br>

                <form action="<?= ROOT_URL ?>admin/comment-logic.php" method="POST">
                    <input type="hidden" name="id" value="<?= $post['id'] ?>">
                    <input type="text" value="<?= $comment ?>" name="comment" placeholder="Comment or Reply">
                    <button type="submit" name="submit" class="btn">Add Comment</button>
                </form>


            <?php else : ?>
                <?php
                // fetch category from categories table using category_id of post
                $category_id = $post['office_id'];
                $category_query = "SELECT * FROM adminaddoffice WHERE id=$category_id";
                $category_result = mysqli_query($connection, $category_query);
                $category = mysqli_fetch_assoc($category_result);
                ?>
                <h3><a href="<?= ROOT_URL ?>user/details-post.php?id=<?= $post['id'] ?>"><?= $post['type'] ?><?= $post['id'] ?></a></h3>
                <a href="<?= ROOT_URL ?>user/category-posts.php?id=<?= $post['office_id'] ?>" class="category__button"><?= $category['title'] ?></a>

                <div class="post__author">
                    <?php
                    // fetch author from users table using author_id
                    $author_id = $post['author_id'];
                    $author_query = "SELECT * FROM adminmanagement WHERE id=$author_id";
                    $author_result = mysqli_query($connection, $author_query);
                    $author = mysqli_fetch_assoc($author_result);
                    ?>
                    <div class="post__author-avatar">
                        <img src="<?= ROOT_URL . 'images/' . $author['picture'] ?>">
                    </div>
                    <div class="post__author-info">
                        <h5>By: <?= "{$author['firstname']} {$author['lastname']}" ?></h5>
                        <small>
                            <?= date("M d, Y - H:i", strtotime($post['date_time'])) ?>
                        </small>
                    </div>
                </div>

                </br>
                <div class="singlepost__thumbnail">
                    <!-- <img src="./images/<?= $post['picture'] ?>"> -->
                    <img src="<?= ROOT_URL . 'images/' . $post['picture'] ?>">
                </div>
                <p class="post__body">
                    <?= $post['body'] ?>
                </p>
                </br>

                <form action="<?= ROOT_URL ?>admin/comment-logic.php" method="POST">
                    <input type="hidden" name="id" value="<?= $post['id'] ?>">
                    <input type="text" value="<?= $comment ?>" name="comment" placeholder="Comment or Reply">
                    <button type="submit" name="submit" class="btn">Add Comment</button>
                </form>
        </div>
    <?php endif ?>
    </div>
</section>
<!-- ============= END OF SINGLE POST ============= -->



<!-- <?php
        include 'partials/footer.php';
        ?> -->