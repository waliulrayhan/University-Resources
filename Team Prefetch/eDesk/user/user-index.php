<?php
include 'partials/header.php';

// fetch 9 posts from posts table
$query = "SELECT * FROM post WHERE status='Approved' AND user_id != '0' ORDER BY date_time DESC LIMIT 9";
$posts = mysqli_query($connection, $query);


?>

</br>
</br>
</br>


<section class="posts <?= $featured ? '' : 'section__extra-margin' ?>">
    <div class="container posts__container">
        <?php while ($post = mysqli_fetch_assoc($posts)) : ?>
            <article class="post">
                <!-- <div class="post__thumbnail">
                    <img src="<?= ROOT_URL . 'images/' . $post['picture'] ?>" width="400" height="200">
                </div> -->
                <div class="post__info">
                    <?php
                    // fetch category from categories table using category_id of post
                    $category_id = $post['office_id'];
                    $category_query = "SELECT * FROM adminaddoffice WHERE id=$category_id";
                    $category_result = mysqli_query($connection, $category_query);
                    $category = mysqli_fetch_assoc($category_result);
                    ?>
                    <h3><?= $post['type'] ?><?= $post['id'] ?></h3>
                    <a href="<?= ROOT_URL ?>user/category-posts.php?id=<?= $post['office_id'] ?>" class="category__button"><?= $category['title'] ?></a>
                    <h4 class="post__title">
                        <!-- <a href="<?= ROOT_URL ?>post.php?id=<?= $post['id'] ?>"><?= $post['title'] ?></a> -->
                        <?= date("d M Y - H:i", strtotime($post['date_time'])) ?>
                    </h4>
                    </br>
                    <p class="post__body">
                        <?php $len = strlen($post['body']); ?>
                        <?php if ($len < 30) : ?>
                            <a href="<?= ROOT_URL ?>user/details-post.php?id=<?= $post['id'] ?>"><?= $post['body'] ?></a>
                        <?php else : ?>
                            <?= substr($post['body'], 0, 30) ?>
                    <h5><a href="<?= ROOT_URL ?>user/details-post.php?id=<?= $post['id'] ?>">See more...</a></h5>
                <?php endif ?>

                </p>
                <div class="post__author">
                    <div class="post__author-info">
                        <h5>Status: <?= $post['comment'] ?></h5>
                    </div>
                </div>
                </div>
            </article>
        <?php endwhile ?>
    </div>
</section>
<!-- ============= END OF POSTS ============= -->